
//------------------------------------------------------------------------------
//

#ifndef COORDINATE_H_INCLUDED
#define COORDINATE_H_INCLUDED

#include <iostream>

class Game;

class Coordinate
{
  private:
    int x_;
    int y_;
    unsigned int attr_;

    void init(int x, int y);

    friend std::ostream& operator<<(std::ostream& out, const Coordinate& c);

  public:
//------------------------------------------------------------------------------
// Constructor
//
    Coordinate();
    Coordinate(int x, int y, unsigned int attr);    
    Coordinate(char x, int y);

    Coordinate(const Coordinate& p);

//------------------------------------------------------------------------------
// Destructor
//
    virtual ~Coordinate();

    const int getX() const;
    const char getXAsChar() const;
    void setX(int x);
    void setY(int y);
    const int getY() const;
    const uint getAttr() const;

    bool operator== (Coordinate const& rhs);

    void print();
};

#endif