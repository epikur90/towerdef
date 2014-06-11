//------------------------------------------------------------------------------
/// Filename: FileIO.cpp
/// Description: TODO
/// Authors: Tutors
/// Group: 00 Tutor all
/// Latest Change: 15.04.2011
//-----------------------------------------------------------------------------

#include <fstream>
#include <iostream>
#include "FileIO.h"
#include "Db.h"
#include "Game.h"
#include "Monster.h"
#include "Tower.h"
#include "Ratio.h"
#include "Map.h"
#include "Coordinate.h"
#include "Spawn.h"
#include "CanNotOpenDbException.h"
#include "CanNotOpenLvlException.h"
#include "DatabaseCorruptException.h"
#include "LevelCorruptException.h"

FileIO::FileIO(Db& db, Game& game)
  : db_(db), game_(game)
{
}
//-----------------------------------------------------------------------------
FileIO::FileIO(Db& db, Game& game, std::string lvl_filename, std::string db_filename)
    : db_(db), game_(game), lvl_filename_(lvl_filename), db_filename_(db_filename)
{
}
//-----------------------------------------------------------------------------
FileIO::~FileIO()
{
}
//-----------------------------------------------------------------------------
void FileIO::readDbFile()
{
  std::ifstream bin_db(db_filename_.c_str(), std::ios::in | std::ios::binary);
  if (!bin_db || !bin_db.good())
  {
    bin_db.close();
    throw CanNotOpenDbException();    
  }
  if (!checkHeader(bin_db))
  {
    bin_db.close();
    throw DatabaseCorruptException();
  }

  unsigned int tower_id = 1;
  unsigned int monster_id = 1;
  unsigned int map_id = 1;
  while(true)
  {
    switch (getChunkType(bin_db))
    {
      case 1: // tower
      {
        Tower* tower = readTower(bin_db, tower_id);
        if (!tower)
        {
          bin_db.close();
          throw DatabaseCorruptException();
        }
        else
        {
          db_.addTower(tower);
          tower_id++;
        }
        break;
      }
      case 2: // monster
      {   
        Monster* monster = readMonster(bin_db, monster_id);
        if (!monster)
        {
          bin_db.close();
          throw DatabaseCorruptException();
        }
        else
        {
          db_.addMonster(monster);
          monster_id++;
        }
        break;
      }
      case 3: // map
      {
        Map* map = readMap(bin_db, map_id);
        if (!map)
        {
          bin_db.close();
          throw DatabaseCorruptException();
        }
        else
        {
          db_.addMap(map);
          map_id++;
        }
        break;
      }
      case -2:  // eof
      {
        bin_db.close();
        return;
      }
      case -1: // corrupt chunk header
      {      
        bin_db.close();
        throw DatabaseCorruptException();
      }
      case 0:  // unknown chunk
      {
        bin_db.close();
        throw DatabaseCorruptException();
      }
    }
  }
}
//-----------------------------------------------------------------------------
void FileIO::readLvlFile()
{
  std::ifstream bin_lvl(lvl_filename_.c_str(), std::ios::in | std::ios::binary);
  if (!bin_lvl || !bin_lvl.good())
  {
    bin_lvl.close();
    throw CanNotOpenLvlException();
  }
  if (!checkHeader(bin_lvl))
  {
    bin_lvl.close();
    throw LevelCorruptException();  
  }

  unsigned int spawn_id;
  while(true)
  {
    switch (getChunkType(bin_lvl))
    {
      case 4: // Level
      { 
        if(!readLevel(bin_lvl))
        {
          bin_lvl.close();
          throw LevelCorruptException();
        }
        break;
      }
      case 5: // Spawn
      {
        Spawn* spawn = readSpawn(bin_lvl, spawn_id);
        if (!spawn)
        {
          bin_lvl.close();
          throw LevelCorruptException();
        }
        else
        {
          db_.addSpawn(spawn);
          spawn_id++;
        }
        break;
      }
      case -2:  // eof
      {
        bin_lvl.close();
        return;
      }
      case -1: // corrupt chunk header
      {      
        bin_lvl.close();
        throw LevelCorruptException();
      }      
      case 0:  // unknown chunk
      {
        bin_lvl.close();
        throw LevelCorruptException();
      }      
    }
  }
}
//-----------------------------------------------------------------------------
bool FileIO::checkHeader(std::ifstream& bin)
{
  std::string magic_number_string = "PROG2014";
  char magic_number[8];
 
  if (readData(bin, magic_number, sizeof(magic_number)))
  {
    magic_number[8] = '\0';
    if(magic_number_string.compare(magic_number))
    {
      return false;
    }
    return true;
  }
  return false;
}
//-----------------------------------------------------------------------------
int FileIO::getChunkType(std::ifstream& bin)
{
  std::string string_tower   = "TOWER\x00\x00\x00";
  std::string string_monster = "MONSTER\x00";
  std::string string_map     = "MAP\x00\x00\x00\x00\x00";
  std::string string_level   = "LEVEL\x00\x00\x00";
  std::string string_spawn   = "SPAWN\x00\x00\x00";
  char chunk[8];
  
  bin.peek();
  if (bin.eof())
  {
    return -2;  // last chunk / eof
  }
  if (!readData(bin, chunk, sizeof(chunk)) || chunk[7] != '\x00')
  {
    return -1; // corrupt chunk
  }
  if (string_tower.compare(chunk) == 0)
  {
    return 1;  // is tower
  }
  if (string_monster.compare(chunk) == 0)
  {
    return 2;  // is monster
  }
  if(string_map.compare(chunk) ==0)
  {
    return 3;  // is map
  }
  if(string_level.compare(chunk) == 0)
  {
    return 4;  // is level
  }
  if(string_spawn.compare(chunk) ==0)
  {
    return 5;  // is spawn
  }
  return 0; // unknown chunk
}
//-----------------------------------------------------------------------------
Tower* FileIO::readTower(std::ifstream& bin, unsigned int id)
{
  unsigned name_length = 0;
  if (!readData(bin, name_length))
  {     
    return 0;
  }
  char name[name_length+1] ;
  unsigned int cost = 0;
  unsigned int damage = 0;
  unsigned int range = 0;
  Ratio ratio;
  unsigned int upID = 0;
  unsigned int attr = 0;
  
  if (readData(bin, name, name_length) && readData(bin, cost) && readData(bin, damage)
      && readData(bin, range) && readData(bin, ratio) && readData(bin, upID) && readData(bin, attr))
  {   
    name[name_length] = '\0';
    std::string name_str = name;
    return new Tower(id, name_str, damage, range, cost, upID, attr, ratio, game_);
  }
  return 0;
}
//-----------------------------------------------------------------------------
Monster* FileIO::readMonster(std::ifstream& bin, unsigned int id)
{
  unsigned name_length = 0;
  if (!readData(bin, name_length))
  {
    return 0;
  }
  char name[name_length+1];
  Ratio ratio = Ratio();
  unsigned int damage = 0;
  unsigned int hp = 0;
  unsigned int reward = 0;
  if (readData(bin, name, name_length) && readData(bin, ratio) && readData(bin, damage)
      && readData(bin, hp) && readData(bin, reward))
  {
    name[name_length] = '\0';
    std::string name_str = name;
    return new Monster(id, name_str, damage, hp, reward, ratio, game_);
  }
  return 0;
}
//-----------------------------------------------------------------------------
Map* FileIO::readMap(std::ifstream& bin, unsigned int id)
{
  unsigned int width = 0;
  unsigned int height = 0;
  std::vector<Coordinate*> fields;
  char field;
  if (readData(bin, width) && readData(bin, height))
  { 
    for(unsigned int col=0; col<height; col++)
    {  
      for(unsigned int row=0; row<width; row++)
      {
        if(!readData(bin, field))
        {
          return 0;
        }
        fields.push_back(new Coordinate(row, col, (uint)field));      
      }
    }
    return new Map(id, width, height, fields);
  }
  return 0;
}
//-----------------------------------------------------------------------------
bool FileIO::readLevel(std::ifstream& bin)
{
  unsigned int map_id = 0;
  unsigned int hp = 0;
  unsigned int cash = 0;
  if (readData(bin, map_id) && readData(bin, hp) && readData(bin, cash))
  { 
    game_.setMapID(map_id);
    game_.setHP(hp);
    game_.setCash(cash);
    db_.incLvlCheck();
    return true;
  }
  return false;
}
//-----------------------------------------------------------------------------
Spawn* FileIO::readSpawn(std::ifstream& bin, unsigned int id)
{
  unsigned int tick = 0;
  unsigned int monster_id = 0;
  Coordinate coordinate;

  if (readData(bin, tick) && readData(bin, monster_id) && 
    readData(bin, coordinate))
  { 
    return new Spawn(tick, monster_id, coordinate);
  }
  return 0;
}
//-----------------------------------------------------------------------------
bool FileIO::readData(std::ifstream& bin, char* data, unsigned int count)
{
  if (bin.read(data, count).good())
  {
    return true;
  }
  return false;
}
//-----------------------------------------------------------------------------
bool FileIO::readData(std::ifstream& bin, char& data)
{
  if (bin.read(reinterpret_cast<char*>(&data), sizeof(data)).good())
  {
    return true;
  }
  return false;
}
//-----------------------------------------------------------------------------
bool FileIO::readData(std::ifstream& bin, unsigned int& data)
{
  if (bin.read(reinterpret_cast<char*>(&data), sizeof(data)).good())
  {
    return true;
  }
  return false;
}
//-----------------------------------------------------------------------------
bool FileIO::readData(std::ifstream& bin, Ratio& data)
{
  unsigned int num, denum;

  if (bin.read(reinterpret_cast<char*>(&num), sizeof(num)).good()
   && bin.read(reinterpret_cast<char*>(&denum), sizeof(denum)).good())
  {
    data.setNumerator(num);
    data.setDenominator(denum);
    return true;
  }
  return false;
}
//-----------------------------------------------------------------------------
bool FileIO::readData(std::ifstream& bin, Coordinate& data)
{
 unsigned int x, y;

  if (bin.read(reinterpret_cast<char*>(&x), sizeof(x)).good()
      && bin.read(reinterpret_cast<char*>(&y), sizeof(y)).good())
  {
    data.setX(y);
    data.setY(y);
    return true;
  }
  return false;
}
//-----------------------------------------------------------------------------
bool FileIO::readData(std::ifstream& bin, bool& data)
{
  char byte;
  if (bin.read(&byte, sizeof(byte)).good())
  {
    if (byte == 0)
    {
      data = false;
    }
    else if (byte == 1)
    {
      data = true;
    }
    else
    {
      return false;
    }
    return true;
  }
  return false;
}