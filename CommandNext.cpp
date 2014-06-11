//------------------------------------------------------------------------------
// CommandNext.cpp
//
// study assistant J��rg M��ller
// Authors: Manuel Papst    1130635
//          Stefan Janisch  0831181
//          Daniel Moser    0831423
//
//-----------------------------------------------------------------------------
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "Command.h"
#include "CommandNext.h"
#include "Game.h"
CommandNext::CommandNext(std::string name) : Command (name)
{
}
//-----------------------------------------------------------------------------
//
CommandNext::~CommandNext()
{
}
//-----------------------------------------------------------------------------
//
uint playRound(Game& board)
{
  //1
  board.incTick();

  //2
  std::vector<Tower*> towers = board.getBuiltTowers();
  for( uint curs=0; curs < towers.size(); curs++)
  {
    towers.at(curs)->incFirePoints();
    while(towers.at(curs)->canShoot())
    {
      std::vector<Monster*> monsters = board.getSpawnedMonsters(); 
      Monster* target = towers.at(curs)->tryRange(monsters);
      if(target)
      {        
        std::cout << towers.at(curs)->getName() << " (" 
          << towers.at(curs)->getCoordinate() << ") " 
          << " fires at " << target->getName() 
          << " (" << target->getCoordinate() << ")." << std::endl;

        if(!target->hit(towers.at(curs)->getDamage()))
        {  
          std::cout << "The monster takes " << towers.at(curs)->getDamage()
          << " damage and survives with " << target->getHP()<<" HP." 
          << std::endl;
        }
        else 
        {
          std::cout << "The monster takes " << towers.at(curs)->getDamage()
          << " damage and dies." << std::endl; 
        }
        towers.at(curs)->decFirePoints();    
        break;
      }
      else
      {
        std::cout << towers.at(curs)->getName() << ": no target" << std::endl;
        break;
      }
      towers.at(curs)->decFirePoints();
    }
  }
  //3 manage monster movement/attacks
  std::vector<Monster*> monsters = board.getSpawnedMonsters();
  for(uint curs=0; curs < monsters.size(); curs++)
  {
    monsters.at(curs)->incMovePoints();
     while(monsters.at(curs)->canMove())
     {
      if(monsters.at(curs)->action())// attack
      {
        bool dead = monsters.at(curs)->attack();
        std::cout << "Arr! " << monsters.at(curs)->getName() 
          << " attacks your base and deals " 
          << monsters.at(curs)->getDamage() << " damage (" 
          << board.getHP() << " HP remaining)." << std::endl;
        if(dead)
        {
          std::cout << "You die." << std::endl;
          return 1;
        }
      }
    }
    monsters.at(curs)->decMovePoints();
   }  
   board.executeDeathNote();
  //4 spawns, deletes spawned Ms from db-spawn-vec
  board.spawn(); 
  return board.isWin();
}
//-----------------------------------------------------------------------------
//
int CommandNext::execute(Game& board, std::vector<std::string>& params)
{
  if(params.size() > 1)
  {
    return ERR_USE;
  }
  unsigned int rounds = 1;
  if(params.size() == 1)
  {
    std::string first_param = params[0];
    std::stringstream ss;
    ss << first_param;
    ss >> rounds;
    if(first_param[0] == '-' || first_param[0] == '+' || !ss.eof())
    {
      std::cout << "Error: invalid number!" << std::endl;
      return ERR_TYPE;
    }
    if(rounds == 0)
    {
      return CMD_SUC;
    }
  }
  if(board.getHP() == 0)
  {
    std::cout << "Error: You are already dead!" << std::endl;    
    return ERR_TYPE;
  }
    if(board.isWin())
  {
    std::cout << "Error: You already won!" << std::endl;    
    return ERR_TYPE;
  }
  for(;rounds > 0; rounds--)
  {
    if(playRound(board)==1)
    {
      return CMD_SUC;
    }
  }
  return CMD_SUC;
}

