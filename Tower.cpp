//------------------------------------------------------------------------------
// Tower.cpp
//
// study assistant Jörg Müller
// Authors: Manuel Papst    1130635
//          Stefan Janisch  0831181
//          Daniel Moser    0831423
//
//------------------------------------------------------------------------------
//

#include <iostream>

#include "Game.h"
#include "Tower.h"
#include "Monster.h"
#include <complex>

//--------------------------------------------------------------------------
//

Tower::Tower(unsigned int id, std::string name, unsigned int damage, unsigned int range,
             unsigned int costs, unsigned int upID, 
             unsigned int attributes, Ratio ratio, Game& game)
  
          : id_(id), name_(name), damage_(damage), range_(range), 
            costs_(costs), upID_(upID), 
            attributes_(attributes), ratio_speed_(ratio), game_(game)


{
  coordinate_.setX(27);
  coordinate_.setY(11);
}

//--------------------------------------------------------------------------
//

Tower::~Tower() 
{
}

	const unsigned int Tower::getID() const
	{
		return id_;
	}

	const unsigned int Tower::getCosts() const
	{
		return costs_;
	}

	const unsigned int Tower::getAttributes() const
	{
		return attributes_;
	}

	const unsigned int Tower::getUpID() const
	{
		return upID_;
	}

  const std::string Tower::getName() const 
  { 
    return name_; 
  }

  const unsigned int Tower::getDamage() const 
  { 
    return damage_; 
  }

  const unsigned int Tower::getRange() const 
  { 
    return range_; 
  }

  const Ratio Tower::getSpeedRatio() const
  {
    return ratio_speed_;
  }

  const Ratio Tower::getPointsRatio() const
  { 
    return ratio_points_;
  }

  const Coordinate Tower::getCoordinate() const
  { 
    return coordinate_;
  }

  const bool Tower::canShoot() const
  { 
    if(ratio_points_.getNumerator() >= ratio_points_.getDenominator())
    {
      return true;
    }
    return false;
  }

//--------------------------------------------------------------------------
// Setter
//

    void Tower::setID(unsigned int id)
	{
		id_ = id;
	}

	void Tower::setCosts(unsigned int costs)
	{
		costs_ = costs;
	}

	void Tower::setAttributes(unsigned int attributes)
	{
		attributes_ = attributes;
	}

	void Tower::setUpID(unsigned int upID)
	{
		upID_ = upID;
	}

  void Tower::setName( std::string name ) 
  { 
    name_ = name ;
  }

  void Tower::setDamage ( unsigned int damage ) 
  { 
    damage_ = damage; 
  }

  void Tower::setRange ( unsigned int range) 
  { 
    range_ = range; 
  }

  void Tower::setSpeedRatio ( Ratio& ratio )
  {
    ratio_speed_ = ratio;
  }

  void Tower::setPointsRatio ( Ratio& ratio )
  { 
    ratio_points_ = ratio;
  }

  void Tower::setCoordinate (Coordinate c)
  { 
    coordinate_ = c;
  }


//--------------------------------------------------------------------------


std::ostream& operator<<(std::ostream& out, const Tower& tower)
{
  out << "Tower - "; 
  out << "id:       " << tower.id_ << std::endl;
  out << "name:     " << tower.name_ << std::endl;
  out << "damage:  " << tower.costs_ << std::endl;
  out << "range:    " << tower.damage_ << std::endl;
  out << "speed:    " << tower.ratio_speed_ << std::endl;
  out << "requires: " << "nothing" << std::endl;
  out << "upgrades: " << "nothing" << std::endl;
  out << "coordinate: " << tower.coordinate_ << std::endl;

  return out;
}


bool Tower::operator==(const Tower& tower)
{
  if ((name_ != tower.name_) || (id_ != tower.id_) || (damage_ != tower.damage_)
      || (costs_ != tower.costs_) ||!(ratio_speed_ == tower.ratio_speed_) ||
      (range_ != tower.range_) || (upID_
      != tower.upID_) || (range_ != tower.range_) ||
      (attributes_ != tower.attributes_))
  {
  	return false;
  }
   
  return true;
}

bool Tower::operator!=(const Tower& tower)
{
  return !(*this == tower);
}


unsigned int Tower::fire()
{
  return 1;//ratio_.currentEvents(obj_->getCurrentTick());
}

void Tower::incFirePoints()
{
  ratio_points_ = ratio_points_ + ratio_speed_; 
}

void Tower::decFirePoints()
{
  ratio_points_.setNumerator(1); 
  ratio_points_.setDenominator(1); 
}

//------------------------------------------------------------------------------
//
double getEuclidianDistance(Coordinate tower, Coordinate monster)
{
  int monster_x = monster.getX();
  int monster_y = monster.getY();

  int tower_x = tower.getX();
  int tower_y = tower.getY();

  int distance_x = (monster_x - tower_x);
  int distance_y = (monster_y - tower_y);

  return sqrt( (distance_x * distance_x) + (distance_y * distance_y) );
}
//------------------------------------------------------------------------------
//
Monster* Tower::tryRange(std::vector<Monster*>& monsters)
{
  for(uint curs=0; curs < monsters.size(); curs++)
  {
    if(getEuclidianDistance(coordinate_, monsters.at(curs)->getCoordinate()) 
        <= range_)
    {
      Monster* target = monsters.at(curs);
      monsters.erase(monsters.begin()+curs);
      return target;
    }
  }
  return 0;
}