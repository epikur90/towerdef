#ifndef SPAWN_H
#define SPAWN_H


//class Coordinate;
#include "Coordinate.h"
class Spawn
{
private:
  unsigned int tick_;
  unsigned int monster_id_;
  Coordinate coordinate_;

  //--------------------------------------------------------------------------
  // Copy Constructor
  Spawn(const Spawn& source);

  //--------------------------------------------------------------------------
  // Private assignment operator
  Spawn& operator=(const Spawn& original);
  friend std::ostream& operator<<(std::ostream& out, const Spawn& s);


public:

  //--------------------------------------------------------------------------
  // Constructor
  Spawn(unsigned int tick, unsigned int monster_id_, Coordinate coordinate);

  //--------------------------------------------------------------------------
  // Destructor
  ~Spawn();

 //--------------------------------------------------------------------------
 // Setter
  void setMonster_id(unsigned int monster_id);
  void setCoordinate(const Coordinate &coordinate);
  void setTick(unsigned int tick);

 //--------------------------------------------------------------------------
 // Getter
  unsigned int getMonsterID() const;
  unsigned int getTick() const;
  Coordinate getCoordinate() const;

};

#endif // SPAWN_H
