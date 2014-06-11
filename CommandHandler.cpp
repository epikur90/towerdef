//------------------------------------------------------------------------------
// CommandHandler.cpp
//
// study assistant Jörg Müller
// Authors: Manuel Papst    1130635
//          Stefan Janisch  0831181
//          Daniel Moser    0831423
//
//------------------------------------------------------------------------------
//

#include <string>
#include <vector>
#include <iostream>
#include <iterator>

#include "CommandHandler.h"
#include "UserInterface.h"

#include "Command.h"
#include "CommandQuit.h"
#include "CommandNext.h"
#include "CommandShow.h"
#include "CommandShop.h"
#include "CommandStats.h"
#include "CommandBuy.h"

//------------------------------------------------------------------------------

const char* CommandHandler::cmd_names[] = {"show",
                                           "next", "shop", "stats", "buy", "quit"};

//------------------------------------------------------------------------------

std::map<std::string, Command*> CommandHandler::commands_;

//------------------------------------------------------------------------------

int CommandHandler::handleCommand(Game& board)
{

  std::vector<std::string> params;
  int ret_val = 0;

  std::string command = UserInterface::readInput();


  if(!UserInterface::splitInput(command, params))
  {
    return ERR_EMPTY;
  }


  if((CmdIsValid(command)) == ERR_CMD)
  {
    return ERR_CMD;
  }

  Command* cmd = commands_[command];

  ret_val = cmd->execute(board,params);
  return ret_val;
}

//------------------------------------------------------------------------------

int CommandHandler::CmdIsValid(std::string command)
{
  for(int cmd_position = 0; cmd_position < CMD_COUNTER; cmd_position++)
  {
    if(cmd_names[cmd_position] == command)
    {
      return cmd_position;
    }
  }

  return ERR_CMD;
}

//------------------------------------------------------------------------------

void CommandHandler::initCmds()
{
  commands_[cmd_names[SHOW]] = new CommandShow(cmd_names[SHOW]);
  commands_[cmd_names[NEXT]] = new CommandNext(cmd_names[NEXT]);
  commands_[cmd_names[SHOP]] = new CommandShop(cmd_names[SHOP]);
  commands_[cmd_names[STATS]] = new CommandStats(cmd_names[STATS]);
  commands_[cmd_names[BUY]] = new CommandBuy(cmd_names[BUY]);
  commands_[cmd_names[QUIT]] = new CommandQuit(cmd_names[QUIT]);
}

//------------------------------------------------------------------------------

void CommandHandler::deleteCmds()
{
  std::map<std::string, Command*>::iterator it;

  for(it = commands_.begin(); it != commands_.end(); ++it)
  {
    delete it->second;
  }

  commands_.clear();
}
