#include <iostream>
#include <vector>
#include <string>
#include <sstream>


#include "Command.h"
#include "CommandBuy.h"
#include "Coordinate.h"
#include "Game.h"
#include "Tower.h"
#include "Db.h"



//------------------------------------------------------------------------------
//

CommandBuy::CommandBuy(std::string name) : Command(name)
{
}

//------------------------------------------------------------------------------
//

CommandBuy::~CommandBuy()
{
}

//------------------------------------------------------------------------------
//

int CommandBuy::execute(Game& board, std::vector<std::string>& params)
{

  if(params.size() != 2)
  {
    return ERR_USE;
  }

    std::string first_param = params[0];
    unsigned int id;
    std::stringstream ss;
    ss << first_param;
    ss >> id;

    if(first_param[0] == '-' || first_param[0] == '+' || !ss.eof())
    {
      std::cout << "Error: Wrong parameter type!" << std::endl;
      return ERR_TYPE;
    }

    std::string second_param = params[1];

    if (second_param.size() > 2)
    {
        std::cout << "Error: Wrong parameter type!" << std::endl;
        return ERR_TYPE;
    }

    std::string input_width_coord = second_param.substr(0,1);
    std::string input_height_coord = second_param.substr(1,2);
    unsigned int height_coord;
    std::stringstream ssa;
    ssa << input_height_coord;
    ssa >> height_coord;

    if (!(input_width_coord[0] >= 'a' && input_width_coord[0] <= 'z' ))
    {
      std::cout << "Error: Wrong parameter type!" << std::endl;
      return ERR_TYPE;
    }

    if(input_height_coord[0] == '-' || input_height_coord[0] == '+' || !ssa.eof())
    {
      std::cout << "Error: Wrong parameter type!" << std::endl;
      return ERR_TYPE;
    }

    int value_coord_width = input_width_coord[0] + 'a';

    std::istringstream buffer(input_height_coord);
    int value_coord_height;
    buffer >> value_coord_height;


    Coordinate tower_coordinate(value_coord_width,value_coord_height);

    int find_id = board.getDb()->findTowerByID(id);
    std::vector<Tower*> tow = board.getTowers();


    if (find_id == -1)
    {
        std::cout <<"Error: invalid ID!" <<std::endl;
        return ERR_TYPE;
    }

    //if Koordinate existiert nicht
    //{
        //std::cout <<"Error: invalid coordinate!" <<std::endl;
        //return ERR_TYPE;
    //}

    if (board.getCash() < tow.at(find_id)->getCosts())
    {
        std::cout <<"Error: You don't have enough money!"<<std::endl;
        return ERR_TYPE;
    }

    if (board.getHP() <= 0)
    {
        std::cout <<"Error: You are already dead!" << std::endl;
        return ERR_TYPE;
    }

    if (board.getMonsters().size() == 0)
    {
        std::cout <<"Error: You already won!" << std::endl;
        return ERR_TYPE;
    }


    tow.at(find_id)->setCoordinate(tower_coordinate);
    board.buildTower(tow.at(find_id));
    board.setCash(board.getCash()-tow.at(find_id)->getCosts());

    std::cout << "Building new tower " << tow.at(find_id)->getName()
    << " at " << tower_coordinate << " for " <<
    tow.at(find_id)->getCosts() << " $." << std::endl;


    return CMD_SUC;
}
