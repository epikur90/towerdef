

#include "Spawn.h"


Spawn::Spawn(unsigned int tick, unsigned int monster_id, Coordinate coordinate)
{
  tick_ = tick;
  monster_id_= monster_id;
  coordinate_ = coordinate;
}

Spawn::~Spawn()
{

}

unsigned int Spawn::getMonsterID() const
{
  return monster_id_;
}

void Spawn::setMonster_id(unsigned int monster_id)
{
  monster_id_ = monster_id;
}

unsigned int Spawn::getTick() const
{
  return tick_;
}

void Spawn::setTick(unsigned int tick)
{
  tick_ = tick;
}
//------------------------------------------------------------------------------

Coordinate Spawn::getCoordinate() const
{
  return coordinate_;
}

void Spawn::setCoordinate(const Coordinate &coordinate)
{
  coordinate_ = coordinate;
}

std::ostream& operator <<(std::ostream& out, const Spawn& s)
{ 
  out << std::endl;		
  out << "Spawn:  " << std::endl;
  out << "tick: " << s.getTick() << std::endl;
  out << "monster_id: " << s.getMonsterID() << std::endl;
  out << "Coord: " << s.getCoordinate() << std::endl;
  out << std::endl;		
  return out;
}