//------------------------------------------------------------------------------
// UserInterface.cpp
//
// study assistant J��rg M��ller
// Authors: Manuel Papst    1130635
//          Stefan Janisch  0831181
//          Daniel Moser    0831423
//
//------------------------------------------------------------------------------
//

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

#include "UserInterface.h"


//------------------------------------------------------------------------------
//

UserInterface::UserInterface()
{
}

//------------------------------------------------------------------------------
//

UserInterface::~UserInterface()
{
}

//------------------------------------------------------------------------------
//

std::string UserInterface::readInput()
{

  std::string input;
  getline(std::cin,input);
  return input;
}

//------------------------------------------------------------------------------
//

bool UserInterface::splitInput(std::string& command, 
                               std::vector<std::string>& params)
{

  std::string input = command;
  size_t check;
  std::string substring;
  bool split = true;

  while( split == true )
  {
    check = input.find(" ");

    if( check == std::string::npos)
    {
      split = false;
    }

    substring.assign(input, 0, check );
    input.assign(input, check + 1, input.size() - check );

    params.push_back(substring);
  }

  command = params[0];
  std::transform(command.begin(), command.end(), command.begin(), ::tolower);
  params.erase(params.begin());

  if(command.empty())
  {
    return false;
  }

  return true;
}
//------------------------------------------------------------------------------
//

std::ostream& UserInterface::getOutStream()
{
  return std::cout;
}
