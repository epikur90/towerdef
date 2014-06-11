//------------------------------------------------------------------------------
// Game.cpp
//
// study assistant Jörg Müller
// Authors: Manuel Papst    1130635
//          Stefan Janisch  0831181
//          Daniel Moser    0831423
//
//------------------------------------------------------------------------------
//

#include <iostream>

#include "CommandHandler.h"
#include "Game.h"
#include "Ratio.h"
#include "Db.h"
#include "Spawn.h"
#include "Map.h"


Game::Game() : tick_counter_(0)
{
  CommandHandler::initCmds();
//  current_map_ = getMapbyID(getMapID());
}
//------------------------------------------------------------------------------
//



void Game::addMonster (Monster* monster)
{
  return monsters_.push_back(monster);
}

//------------------------------------------------------------------------------
//

void Game::buildTower (Tower* tower)
{
  return built_towers_.push_back(tower);
}

//------------------------------------------------------------------------------
//

void Game::addToDeathNote (uint id)
{
  death_note_.push_back(id);
}

//------------------------------------------------------------------------------
//

void Game::executeDeathNote ()
{
  for(uint curs = 0; curs < death_note_.size(); curs++)
  {
        killMonster(death_note_.at(curs));
  }
}


//------------------------------------------------------------------------------
//


int Game::run()
{
  Ratio hallo(7,3);
  Ratio add(3,2);
  Ratio sum = add + hallo;
  // std::cout << sum << std::endl;
  // std::cout << sum + 2 << std::endl;
  // std::cout << sum - 2 << std::endl;

  int ret_val;
  bool is_running = true;


  while(is_running == true )
  {

    std::cout << "sep> ";


    if( (ret_val = CommandHandler::handleCommand(*this)) == EXIT )
    {
      is_running = false;
    }

    switch(ret_val)
    {
      case ERR_CMD:
        std::cout << "Error: Unknown command!\n";
        break;
      case ERR_USE:
        std::cout << "Error: Wrong paramter count!\n";
    }
  }

  return 0;
}

const unsigned int Game::getCurrentTick() const
{
  return tick_counter_;
}

Db* Game::getDb() const
{
  return db_;
}
const unsigned int Game::getCash() const
{
  return cash_;
}

const bool Game::isWin() const
{
  if(spawned_monsters_.size() == 0 && db_->getSpawns()->size() == 0)
  {
    return true;
  }
  return false;
}

const unsigned int Game::getMapID() const
{
  return map_id_;
}

const unsigned int Game::getWidth() const
{
  if(db_)
  {
    return db_->getWidth();
  }
  return 0;
}
const unsigned int Game::getHeight() const
{
  if(db_)
  {
    return db_->getHeight();
  }
  return 0;
}
const unsigned int Game::getHP() const
{
  return hp_;
}

//------------------------------------------------------------------------------
//
const std::vector<Monster*> Game::getMonsters() const
{
  return db_->getMonsters();
}
//------------------------------------------------------------------------------
//

const std::vector<Monster*> Game::getSpawnedMonsters() const
{
  return spawned_monsters_;
}
//------------------------------------------------------------------------------
//
const std::vector<Tower*> Game::getTowers() const
{
    return db_->getTowers();
}
//------------------------------------------------------------------------------
//
const std::vector<Tower*> Game::getBuiltTowers() const
{
    return built_towers_;
}
//------------------------------------------------------------------------------
//

Game::~Game()
{

  for(int i = 0; i < (int) monsters_.size(); i++)
  {
    delete monsters_.at(i);
  }

  for(int i = 0; i < (int) towers_.size(); i++)
  {
    delete towers_.at(i);
  }

  CommandHandler::deleteCmds();
}

void Game::incTick()
{
  tick_counter_++;
}

void Game::setTickCounter(unsigned int tick_counter)
{ 
  tick_counter_ = tick_counter; 
}

void Game::setDb(Db* db)
{
  db_ = db;
}

void Game::setMapID(unsigned int id)
{
  map_id_ = id;
}

void Game::setHP(unsigned int hp)
{
  hp_ = hp;
}

void Game::setCash(unsigned int cash)
{
  cash_ = cash;
}

bool Game::spawn()
{
  bool spawnflag = false;
  std::vector<Spawn*>* spawns = db_->getSpawns();
  for(uint curs=0; curs < spawns->size(); curs++)
  {
    if(spawns->at(curs)->getTick() == tick_counter_)
    {
      if(!db_->monsterIdExists(spawns->at(curs)->getMonsterID())
       || spawns->at(curs)->getCoordinate().getAttr() > 7
       || spawns->at(curs)->getCoordinate().getAttr() < 3) 
      {
        return spawnflag;
      }
      spawned_monsters_.push_back(db_->getMonster(spawns->at(curs)->getMonsterID()) );
      db_->addToDeleteList(spawns->at(curs)->getMonsterID());
      spawnflag = true;
    }
  }
  db_->executeDeleteList();
  return spawnflag; 
}

void Game::killMonster(uint id)
{
  for(uint curs=0; curs < spawned_monsters_.size(); curs++)
  {
    if(spawned_monsters_.at(curs)->getID() == id)
    {
      spawned_monsters_.erase(spawned_monsters_.begin()+curs);
    }    
  }  
}
