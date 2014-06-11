#include <iostream>
#include <vector>
#include <string>

#include "Command.h"
#include "CommandStats.h"

//------------------------------------------------------------------------------
//

CommandStats::CommandStats(std::string name) : Command(name)
{
}

//------------------------------------------------------------------------------
//

CommandStats::~CommandStats()
{
}

//------------------------------------------------------------------------------
//

int CommandStats::execute(Game& board, std::vector<std::string>& params)
{

  if(params.size() != 0)
  {
    return ERR_USE;
  }

  std::cout << "CommandStats" << std::endl;
  return EXIT;
}
