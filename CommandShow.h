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

#ifndef SHOWCOMMAND_H
#define SHOWCOMMAND_H

class CommandShow : public Command
{

  private:
    //--------------------------------------------------------------------------
    // Private copy constructor

    CommandShow(const CommandShow& original);

    //--------------------------------------------------------------------------
    // Private assignment operator

    CommandShow& operator=(const CommandShow& original);

  public:

    //--------------------------------------------------------------------------
    // Consturctor

    CommandShow(std::string name);

    //--------------------------------------------------------------------------
    // Consturctor

    virtual ~CommandShow();

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param board The board where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action

    int execute(Game& board, std::vector<std::string>& params);
    
};

#endif