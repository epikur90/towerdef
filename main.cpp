//------------------------------------------------------------------------------
// Filename: main.cpp
// Description:
//
// Author(s): Tutor
// Created on:   06.02.2014
// Last changed: 06.02.2014
//------------------------------------------------------------------------------

#include "Game.h"
#include "Monster.h"
#include "Tower.h"

#include "Db.h"
#include "UserInterface.h"
#include "CorruptionException.h"

#include<fstream>
#include<iostream>
#include<string>
#include<exception>
//------------------------------------------------------------------------------
int main(int argc, char* argv[])
{

  std::string bonusflag = "-b";
  if(argc < 3 || argc > 4 || (argc == 4 && bonusflag.compare(argv[3])))
  {
    UserInterface::getOutStream() <<
"Error: Wrong Argument Count: \"./towerdefense <Levelfile> <DB-File> [-b]\""
        << std::endl;
    return 1;
  }
  std::string filename_lvl = argv[1];
  std::string filename_db = argv[2];
  try
  {
    Game game;
    Db db(game, filename_lvl, filename_db);
    game.run();
  }
  catch(CorruptionException& e)
  {
    std::cout << e.what() << std::endl;
    return e.ret();
  }
  catch(std::bad_alloc& ba)
  {
    std::cout << "Error: Out of Mana!" << std::endl;
    return 8;
  }
  return 0;
}
