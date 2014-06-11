//------------------------------------------------------------------------------
// CommandNext.h
//
// study assistant Jörg Müller
// Authors: Manuel Papst    1130635
//          Stefan Janisch  0831181
//          Daniel Moser    0831423
//
//------------------------------------------------------------------------------
//

#ifndef NEXTCOMMAND_H
#define NEXTCOMMAND_H

class CommandNext : public Command
{

private:

    //-------------------------------------------------------------------------
    // Private copy constructor
    CommandNext(const CommandNext& original);

    //-------------------------------------------------------------------------
    // Private assignment operator
    CommandNext& operator=(const CommandNext& original);

  public:

    //-------------------------------------------------------------------------
    // Consturctor
    CommandNext(std::string name);

    //-------------------------------------------------------------------------
    // Consturctor
    virtual ~CommandNext();


    //-------------------------------------------------------------------------
    // Executes the command.
    // @param board The board where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action
    int execute(Game& board, std::vector<std::string>& params);

};

#endif //NEXTCOMMAND_H