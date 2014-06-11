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

#ifndef COMMANDQUIT_H
#define COMMANDQUIT_H

class CommandQuit : public Command
{

  private:

    //--------------------------------------------------------------------------
    // Private copy constructor

    CommandQuit(const CommandQuit& original);

    //--------------------------------------------------------------------------
    // Private assignment operator

    CommandQuit& operator=(const CommandQuit& original);

public:

    //--------------------------------------------------------------------------
    // Consturctor

    CommandQuit( std::string name );

    //--------------------------------------------------------------------------
    // Destructor

    virtual ~CommandQuit();

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param board The board where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action

    int execute(Game& board, std::vector<std::string>& params); 

};

#endif //COMMANDQUIT_H