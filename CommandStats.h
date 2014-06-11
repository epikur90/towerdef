#ifndef COMMANDSTATS_H
#define COMMANDSTATS_H

class CommandStats : public Command
{

  private:

    //--------------------------------------------------------------------------
    // Private copy constructor

    CommandStats(const CommandStats& original);

    //--------------------------------------------------------------------------
    // Private assignment operator

    CommandStats& operator=(const CommandStats& original);

public:

    //--------------------------------------------------------------------------
    // Consturctor

    CommandStats( std::string name );

    //--------------------------------------------------------------------------
    // Destructor

    virtual ~CommandStats();

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param board The board where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action

    int execute(Game& board, std::vector<std::string>& params);

};


#endif // COMMANDSTATS_H
