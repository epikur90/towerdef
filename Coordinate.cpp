//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//
#include "Coordinate.h"
#include "Game.h"

#include <cctype>
#include <iostream>

using std::cout;
using std::endl;

Coordinate::Coordinate()
{
}
//------------------------------------------------------------------------------
 Coordinate::Coordinate(int x, int y, unsigned int attr) : attr_(attr)
{
  init(x, y);
}

//------------------------------------------------------------------------------
 Coordinate::Coordinate(char x, int y)
{
  init((x + 'a'), y);
}

//------------------------------------------------------------------------------
 Coordinate::Coordinate(const Coordinate& p)
{
  init(p.getX(), p.getY());
}

//------------------------------------------------------------------------------
 Coordinate::~Coordinate()
{
}

//------------------------------------------------------------------------------
 void Coordinate::init(int x, int y)
{
  setX(x);
  setY(y);
}

//------------------------------------------------------------------------------
 void Coordinate::setX(int x)
{
  x_ = x;
}

//------------------------------------------------------------------------------
 void Coordinate::setY(int y)
{
  y_ = y;
}

//------------------------------------------------------------------------------
const int Coordinate::getX() const
{
  return x_;
}

//------------------------------------------------------------------------------
const char Coordinate::getXAsChar() const
{
  return x_ + 'a';
}

//------------------------------------------------------------------------------
const int Coordinate::getY() const
{
  return y_;
}

//------------------------------------------------------------------------------
const uint Coordinate::getAttr() const
{
  return attr_;
}

//------------------------------------------------------------------------------
 bool Coordinate::operator== (Coordinate const& rhs)
{
  return getX() == rhs.getX() && getY() == rhs.getY();
}

std::ostream& operator <<(std::ostream& out, const Coordinate& c)
{ 
  out << c.getXAsChar() << c.getY();
  return out;
}
//------------------------------------------------------------------------------
 void Coordinate::print()
{
  cout << getXAsChar() << y_ << endl;
}
