#ifndef COMMANDSHOP_H
#define COMMANDSHOP_H

class CommandShop : public Command
{

  private:

    //--------------------------------------------------------------------------
    // Private copy constructor

    CommandShop(const CommandShop& original);

    //--------------------------------------------------------------------------
    // Private assignment operator

    CommandShop& operator=(const CommandShop& original);

public:

    //--------------------------------------------------------------------------
    // Consturctor

    CommandShop( std::string name );

    //--------------------------------------------------------------------------
    // Destructor

    virtual ~CommandShop();

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param board The board where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action

    int execute(Game& board, std::vector<std::string>& params);

};


#endif // COMMANDSHOP_H
