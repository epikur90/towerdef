#ifndef COMMANDBUY_H
#define COMMANDBUY_H

class CommandBuy : public Command
{

  private:

    //--------------------------------------------------------------------------
    // Private copy constructor

    CommandBuy(const CommandBuy& original);

    //--------------------------------------------------------------------------
    // Private assignment operator

    CommandBuy& operator=(const CommandBuy& original);

public:

    //--------------------------------------------------------------------------
    // Consturctor

    CommandBuy( std::string name );

    //--------------------------------------------------------------------------
    // Destructor

    virtual ~CommandBuy();

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param board The board where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action

    int execute(Game& board, std::vector<std::string>& params);

};


#endif // COMMANDBUY_H
