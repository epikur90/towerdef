//------------------------------------------------------------------------------
// UserInterface.h
//
// study assistant J��rg M��ller
// Authors: Manuel Papst    1130635
//          Stefan Janisch  0831181
//          Daniel Moser    0831423
//
//------------------------------------------------------------------------------
//

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

class UserInterface
{

  private:

    //--------------------------------------------------------------------------
    // Private copy constructor

    UserInterface (const UserInterface& source);

    //--------------------------------------------------------------------------
    // Private assigment operator

    UserInterface &operator= ( const UserInterface& source);

  public:

    //--------------------------------------------------------------------------
    // Consturctor

    UserInterface();

    //--------------------------------------------------------------------------
    // Destructor

    virtual ~UserInterface();

    //--------------------------------------------------------------------------
    // Reads the input from the command line
    // @return input string
    //

    static std::string readInput();

    //--------------------------------------------------------------------------
    // Splits the input into command and params
    // @param command string entered
    // @param params vector with params
    // @return false if no input

    static bool splitInput(std::string& command, 
    std::vector<std::string>& params);

    //--------------------------------------------------------------------------
    // return outstream
    //
    static std::ostream& getOutStream();

};

#endif //USERINTERFACE_H
