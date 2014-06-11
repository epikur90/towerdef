//------------------------------------------------------------------------------
// Monster.cpp
//
// study assistant Jörg Müller
// Authors: Manuel Papst    1130635
//          Stefan Janisch  0831181
//          Daniel Moser    0831423
//
//------------------------------------------------------------------------------
//

#include <iostream>
#include <string>

#include "Game.h"
#include "Monster.h"
#include "Coordinate.h"
#include "Db.h"
#include "Map.h"

//--------------------------------------------------------------------------






Monster::Monster(unsigned int id, std::string name, unsigned int damage, 
                  unsigned int hp, unsigned int reward, Ratio ratio, Game& game) 

                  : id_(id), name_(name), damage_(damage), 
                    hp_(hp), reward_(reward), ratio_speed_(ratio), 
                    game_(game)
{
}

//--------------------------------------------------------------------------

Monster::~Monster()
{
}

bool Monster::hit(uint damage)
{
  if(damage >= hp_)
  {
    game_.killMonster(id_);
    return true;
  }
  else
  {
    hp_ -= damage;
    return false;
  }
}
//--------------------------------------------------------------------------

bool Monster::action()
{
  switch(coordinate_.getAttr())
  {
    case 0:
    {
      game_.addToDeathNote(id_);
      return false;
    }
    case 1:
    {
      game_.addToDeathNote(id_);

      return false;      
    }
    case 2:
    {
      return true;
    }
    case 7:
    {
      this->move(last_dir_);
      break;
    }
    case 8:
    {
      game_.addToDeathNote(id_);
      return false;
    }
    default:
    {
      this->move(coordinate_.getAttr());
      break;
    }
  }
  return false;
}
//--------------------------------------------------------------------------
void Monster::move(uint dir)
{
  switch(dir)
  {
   case 3:
    {
      // north
      this->setCoordinate( 
      *game_.getDb()->getMap(game_.getMapID())->getNorthCoord(coordinate_));
      last_dir_ = 3;
      break;
    }
    case 4:
    {
      // east
      this->setCoordinate( 
      *game_.getDb()->getMap(game_.getMapID())->getEastCoord(coordinate_));      
      last_dir_ = 4;
      break;
    }
    case 5:
    {
      // south
      this->setCoordinate( 
      *game_.getDb()->getMap(game_.getMapID())->getSouthCoord(coordinate_));       
      last_dir_ = 5;
      break;
    }
    case 6:
    {
      // west
      this->setCoordinate( 
      *game_.getDb()->getMap(game_.getMapID())->getWestCoord(coordinate_)); 
      last_dir_ = 6;
      break;
    } 
  }
  if(coordinate_.getAttr() < 2)
  {
      game_.addToDeathNote(id_);
  }
}
//--------------------------------------------------------------------------
bool Monster::attack()
{
  if(damage_ >= game_.getHP() )
  {
    game_.setHP(0);
    return true;
  }
  else
  {
    game_.setHP(game_.getHP() - damage_);
    return false;
  }

}
//--------------------------------------------------------------------------
// Getter
const unsigned int Monster::getID() const
{
    return id_;
}
//--------------------------------------------------------------------------
const std::string Monster::getName() const
{
  return name_;
}
//--------------------------------------------------------------------------
const unsigned int Monster::getDamage() const
{
  return damage_;
}
//--------------------------------------------------------------------------
const unsigned int Monster::getHP() const
{
  return hp_ ;
//--------------------------------------------------------------------------
}
const unsigned int Monster::getReward() const
{
  return reward_ ;
}
//--------------------------------------------------------------------------
const Ratio Monster::getRatioSpeed() const
{
  return ratio_speed_ ;
}
//--------------------------------------------------------------------------
const Ratio Monster::getRatioPoints() const 
{
  return ratio_points_ ;
}
//--------------------------------------------------------------------------
const Coordinate Monster::getCoordinate() const 
{
  return coordinate_ ;
}
//--------------------------------------------------------------------------
const bool Monster::isAlive() const 
{
  if(coordinate_.getX() != 27 && coordinate_.getY() != 11)
  {
    return true;
  }
  return false;
}
//--------------------------------------------------------------------------
const bool Monster::canMove() const
{
  if(ratio_points_.getNumerator() >= ratio_points_.getDenominator())
  {
    return true;
  }
  return false;
}

//--------------------------------------------------------------------------
// Setter
void Monster::setID(unsigned int id)
{
    id_ = id;
}
//--------------------------------------------------------------------------
void Monster::setName(std::string name)
{
    name_ = name;
}
//--------------------------------------------------------------------------
void Monster::setDamage(unsigned int damage)
{
  damage_ = damage;
}
//--------------------------------------------------------------------------
void Monster::setHP(unsigned int health_points)
{
  hp_ = health_points;
}
//--------------------------------------------------------------------------
void Monster::setReward(unsigned int reward)
{
  reward_ = reward ;
}
//--------------------------------------------------------------------------
void Monster::setRatioSpeed(Ratio &ratio_speed)
{
  ratio_speed_ = ratio_speed;
}
//--------------------------------------------------------------------------
void Monster::setRatioPoints(Ratio &ratio_points)
{
   ratio_points_ = ratio_points;
}
//--------------------------------------------------------------------------
void Monster::setCoordinate(Coordinate& c) 
{
  coordinate_ = c;
}
//--------------------------------------------------------------------------
void Monster::incMovePoints()
{
  ratio_points_ = ratio_points_ + ratio_speed_;
}
//--------------------------------------------------------------------------
void Monster::decMovePoints()
{
  ratio_points_.setNumerator(1);
  ratio_points_.setDenominator(1);
}
//--------------------------------------------------------------------------
// Operator
std::ostream& operator <<(std::ostream& out, const Monster& m)
{ 
  out << "Monster - ";
  out << "id:       " << m.id_ << std::endl;
  out << "name:     " << m.name_ << std::endl;
  out << "damage:  " << m.damage_ << std::endl;
  out << "hp:       " << m.hp_ << std::endl;
  out << "reward:   " << m.reward_ << std::endl;
  out << "speed:    " << m.ratio_speed_ << std::endl;
  out << "points:   " << m.ratio_points_ << std::endl;

  return out;
}