//------------------------------------------------------------------------------
// CommandQuit.h
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
#include "CommandQuit.h"

//------------------------------------------------------------------------------
//

CommandQuit::CommandQuit(std::string name) : Command(name)
{
}

//------------------------------------------------------------------------------
//

CommandQuit::~CommandQuit()
{
}

//------------------------------------------------------------------------------
//

int CommandQuit::execute(Game& board, std::vector<std::string>& params)
{

  if(params.size() != 0)
  {
    return ERR_USE;
  }

  std::cout << "Thanks for playing, bye!" << std::endl;
  return EXIT;
}