#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "Command.h"
#include "CommandShop.h"
#include "Game.h"

//------------------------------------------------------------------------------
//

CommandShop::CommandShop(std::string name) : Command(name)
{
}

//------------------------------------------------------------------------------
//

CommandShop::~CommandShop()
{
}

//------------------------------------------------------------------------------
//

int CommandShop::execute(Game& board, std::vector<std::string>& params)
{

  std::vector<Tower*> tow = board.getTowers();

  if(params.size() > 1)
  {
    return ERR_USE;
  }

  if(params.size() == 0)
  {
  	

  	for( unsigned int i = 0; i < (unsigned int) board.getTowers().size(); i++)
  	{
      	std::cout << tow.at(i)->getID() << ":" 
      	<< tow.at(i)->getName() << std::endl;
  	}
  }

  if(params.size() == 1)
  {
  	std::string first_param = params[0];
    unsigned int tower_id;
    std::stringstream ss;
    ss << first_param;
    ss >> tower_id;
    tower_id--;
    

    if( (unsigned int) board.getTowers().size() <= tower_id ||
      first_param[0] == '-' || first_param[0] == '+' || !ss.eof())
     {
      std::cout << " Error: invalid ID!" << std::endl;
      return ERR_TYPE;
     }

  std::cout << *(tow.at(tower_id)) << std::endl;

  		
  	
  	
  }  

  return CMD_SUC;
}
