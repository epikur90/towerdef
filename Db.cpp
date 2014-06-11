//------------------------------------------------------------------------------
/// Filename: Db.cpp
/// Description: TODO
/// Authors: Tutors
/// Group: 00 Tutor all
/// Latest Change: 15.04.2011
//------------------------------------------------------------------------------

#include "Db.h"
#include "FileIO.h"
#include "Tower.h"
#include "Map.h"
#include "Spawn.h"
#include "Game.h"
#include "Coordinate.h"
#include "DatabaseCorruptException.h"
#include "LevelCorruptException.h"
#include "IdDoesNotExistException.h"
#include "InvalidCoordException.h"
#include <map>
#include <vector>
#include <iostream>

//------------------------------------------------------------------------------
Db::Db(Game& game, std::string lvl_filename, std::string db_filename) :
 lvl_check_(0), game_(game), fio_(*this, game, lvl_filename, db_filename)
{  
  fio_.readDbFile();
  fio_.readLvlFile();
  corruptionCheck();
  game_.setDb(this);
  // debugList();
}
//------------------------------------------------------------------------------
Db::~Db()
{
  clear();
}
//------------------------------------------------------------------------------
void Db::clear()
{
  for (unsigned int mo = 0; mo < monsters_.size(); mo++)
  {
    delete monsters_[mo];
  }
  for (unsigned int to = 0; to < towers_.size(); to++)
  {
    delete towers_[to];
  }
  for (unsigned int ma = 0; ma < maps_.size(); ma++)
  {
    delete maps_[ma];
  }
  for (unsigned int sp = 0; sp < spawns_.size(); sp++)
  {
    delete spawns_[sp];
  }
}
//------------------------------------------------------------------------------
unsigned int Db::getMonsterCount() const
{
  return monsters_.size();
}
//------------------------------------------------------------------------------
unsigned int Db::getTowerCount() const
{
  return towers_.size();
}
//------------------------------------------------------------------------------
unsigned int Db::getMapCount() const
{
  return maps_.size();
}
//------------------------------------------------------------------------------
const unsigned int Db::getCash() const
{
  return cash_;
}
//------------------------------------------------------------------------------
const unsigned int Db::getWidth() const
{
  return width_;
}
//------------------------------------------------------------------------------
const unsigned int Db::getHeight() const
{
  return height_;
}
//------------------------------------------------------------------------------
const unsigned int Db::getHP() const
{
  return hp_;
}
const std::vector<Monster*> Db::getMonsters() const
{
  return monsters_;
}
//------------------------------------------------------------------------------
const std::vector<Tower*> Db::getTowers() const
{
  return towers_;
}
//------------------------------------------------------------------------------
std::vector<Spawn*>* Db::getSpawns() 
{
  return &spawns_;
}
//------------------------------------------------------------------------------
Monster* Db::getMonster(unsigned int id) const
{
  if (id >= monsters_.size())
    return 0;
  return monsters_.at(id);
}
//------------------------------------------------------------------------------
Tower* Db::getTower(unsigned int id) const
{
  if (id >= towers_.size())
    return 0;
  return towers_.at(id);
}
//------------------------------------------------------------------------------
Map* Db::getMap(unsigned int id) const
{
  if (id >= maps_.size())
    return 0;
  return maps_.at(id);
}
//------------------------------------------------------------------------------
unsigned int Db::addMonster(Monster* monster)
{
  monsters_.push_back(monster);
  return monsters_.size() - 1;
}
//------------------------------------------------------------------------------
unsigned int Db::addTower(Tower* tower)
{
  towers_.push_back(tower);
  return towers_.size() - 1;
}
//------------------------------------------------------------------------------
unsigned int Db::addMap(Map* map)
{
  maps_.push_back(map);
  return maps_.size() - 1;
}
//------------------------------------------------------------------------------
unsigned int Db::addSpawn(Spawn* spawn)
{
  spawns_.push_back(spawn);
  return spawns_.size();
}
//------------------------------------------------------------------------------
void Db::addToDeleteList(uint id)
{
  delete_list_.push_back(id);
}
//------------------------------------------------------------------------------
void Db::executeDeleteList()
{
    for(uint curs = 0; curs < delete_list_.size(); curs++)
  {
        deleteSpawn(delete_list_.at(curs));
  }
}

void Db::deleteSpawn(uint id)
{
  for(uint curs=0; curs < spawns_.size(); curs++)
  {
    if(spawns_.at(curs)->getMonsterID() == id)
    {
      spawns_.erase(spawns_.begin()+curs);
    }    
  }  

}

//------------------------------------------------------------------------------
void Db::incLvlCheck() 
{
  lvl_check_++;
}
//------------------------------------------------------------------------------
void Db::corruptionCheck() 
{  
  if(!validateMaps())
  {
      throw InvalidCoordException();
  }
  for(uint count_s=0; count_s < spawns_.size();count_s++)
  {
    if(spawns_.at(count_s)->getTick() < 1
    ||  !monsterIdExists(spawns_.at(count_s)->getMonsterID())
    ||  maps_.size() < 1)    
    {
      throw DatabaseCorruptException();
    }
    if(!validateCoords(spawns_.at(count_s)->getCoordinate(), game_.getMapID()))
    {
      throw InvalidCoordException();
    }
  }
  if(lvl_check_ != 1)
  {
    throw LevelCorruptException();
  }
  if(!mapIdExists(game_.getMapID()))
  {
    throw IdDoesNotExistException();
  }
} 
//------------------------------------------------------------------------------
bool Db::monsterIdExists(unsigned int id) const
{
  for(unsigned int count=0; count<monsters_.size(); count++)
  {
    if(monsters_.at(count)->getID() == id)
    {
      return true;
    }
  }
  return false;
}
//------------------------------------------------------------------------------
bool Db::towerIdExists(unsigned int id) const
{
  for(unsigned int count=0; count<towers_.size(); count++)
  {
    if(towers_.at(count)->getID() == id)
    {
      return true;
    }
  }
  return false;
}
//------------------------------------------------------------------------------
bool Db::mapIdExists(unsigned int id) const
{
  for(unsigned int count=0; count<maps_.size(); count++)
  {
    if(maps_.at(count)->getID() == id)
    {
      return true;
    }
  }
  return false;
}
//------------------------------------------------------------------------------
bool Db::validateMaps() const
{  
  for (uint count_m=0; count_m < maps_.size(); count_m++)
  {
    if(maps_.at(count_m)->getWidth() > 26
    || maps_.at(count_m)->getHeight() > 9)
    {
      return false;
    }
    // check field attributes 0 < x < 7
    std::vector<Coordinate*> fields = maps_.at(count_m)->getFields();
    for(uint curs=0; curs < fields.size(); curs++)
    {
      if(fields.at(curs)->getAttr() < 0
      || fields.at(curs)->getAttr() > 7)
      {
        return false;
      }
    }
  }
  return true;
}
//------------------------------------------------------------------------------
bool Db::validateCoords(Coordinate coord, uint map_id) const
{ 
  if(coord.getX() < 0 || coord.getY() < 0)
  {
    return false;
  }
  if(coord.getX() > (int)maps_.at(map_id-1)->getWidth()
    ||coord.getY() > (int)maps_.at(map_id-1)->getHeight())
  {
    return false;
  }
  return true;
}
//------------------------------------------------------------------------------
int Db::findTowerByID(uint id)
{
  for (uint curs= 0; curs < towers_.size(); curs++)
  {
    if(towers_.at(curs)->getID() == id)
    {
      return curs;
    }
  }
  return -1;
}
//------------------------------------------------------------------------------
const void Db::debugList() const
{
  std::cout << getMonsterCount() << " Monster(s)." << std::endl;
  std::cout << getTowerCount() << " Tower(s)." << std::endl;
  std::cout << getMapCount() << " Map(s)." << std::endl;
  std::cout << spawns_.size() << " Spawn(s)." << std::endl;
  
  std::cout << std::endl;
  for(unsigned int i=0; i<getMonsterCount(); i++)
  {
    std::cout << *monsters_.at(i) << std::endl;
  }
  for(unsigned int i=0; i<getTowerCount(); i++)
  {
    std::cout << *towers_.at(i) << std::endl;
  }

    for(unsigned int i=0; i<maps_.size(); i++)
  {
    std::vector<Coordinate*> fields = maps_.at(i)->getFields();

    for(uint j=0; j < fields.size(); j++)
    {
      if(j % maps_.at(i)->getWidth() == 0)
      {      
        std::cout << std::endl;
      }
      std::cout << *(fields.at(j));
    }
      std::cout << std::endl;
      std::cout << std::endl;
      std::cout << std::endl;

  }

  for(unsigned int i=0; i<spawns_.size(); i++)
   {
     std::cout << *spawns_.at(i) << std::endl;
   }
}
