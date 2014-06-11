//------------------------------------------------------------------------------
// CommandShow.cpp
//
// study assistant Jörg Müller
// Authors: Manuel Papst    1130635
//          Stefan Janisch  0831181
//          Daniel Moser    0831423
//
//------------------------------------------------------------------------------
//

#include <iostream>
#include <vector>
#include <string>

#include "Command.h"
#include "CommandShow.h"
#include "Game.h"

//------------------------------------------------------------------------------
//

CommandShow::CommandShow(std::string name) : Command (name)
{
}

//------------------------------------------------------------------------------
//

CommandShow::~CommandShow()
{
}

//------------------------------------------------------------------------------
//

int CommandShow::execute(Game& board, std::vector<std::string>& params)
{

  if(params.size() != 0)
  {
    return ERR_USE;
  }

  std::cout << "cash: " <<
  board.getCash() <<
  "$, Life: " <<
  board.getHP() <<
  " HP" << std::endl;


  for(unsigned int j = 0; j < board.getHeight(); j++ )
  {
    std::cout << "+";

    for(unsigned int i = 0; i < board.getWidth(); i++)
    {
      std::cout << "-+";
    }

    std::cout << std::endl << "|";

    for(unsigned int i = 0; i < board.getWidth(); i++)
    {
      std::cout << " |";
    }
    std::cout << std::endl;
  }

    std::cout << "+";

    for(unsigned int i = 0; i < board.getWidth(); i++)
    {
      std::cout << "-+";
    }

  std::cout << std::endl;

  return CMD_SUC;
}