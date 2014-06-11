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

#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <map>

#include "CommandDefines.h"

class Game;
class Command;

class CommandHandler
{
  private:

    //--------------------------------------------------------------------------
    // Private copy constructor

    CommandHandler(const CommandHandler& source);

    //--------------------------------------------------------------------------
    // Private assignment operator

    CommandHandler &operator= (const CommandHandler& source);


  public:

    //--------------------------------------------------------------------------
    // Consturctor

    CommandHandler() throw(std::bad_alloc);

    //--------------------------------------------------------------------------
    // Consturctor

    virtual ~CommandHandler() throw();

    //--------------------------------------------------------------------------
    // Handles the entered Command.
    // @param board The board where action should be performed on
    // @return Integer representing the success of the action

    static int handleCommand(Game& board);

    //--------------------------------------------------------------------------
    // Check if the entered Command is a valid Command.
    // @param command The command to validate
    // @return Integer representing the success of the action

    static int CmdIsValid(std::string command);

    //--------------------------------------------------------------------------
    // Initializes the Commands to Map
    //

    static void initCmds();

    //--------------------------------------------------------------------------
    // Deletes the Commands
    //

    static void deleteCmds();

    //--------------------------------------------------------------------------
    // Array with accepted Commands
    //

    static const char* cmd_names[CMD_COUNTER];

    //--------------------------------------------------------------------------
    // Map Storage for Commands
    //

    static std::map<std::string, Command*> commands_;
};

#endif //COMMANDHANDLER_H