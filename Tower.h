//------------------------------------------------------------------------------
// Tower.h
//
// study assistant J��rg M��ller
// Authors: Manuel Papst    1130635
//          Stefan Janisch  0831181
//          Daniel Moser    0831423
//
//------------------------------------------------------------------------------
//

#ifndef TOWER_H
#define TOWER_H

#include <string>
#include "Ratio.h"
#include "Coordinate.h"


class Game;
class Monster;


class Tower
{
  private:
    //--------------------------------------------------------------------------
    // Private Class Members
    unsigned int id_;
    std::string name_;
    unsigned int damage_;
    unsigned int range_;
    unsigned int costs_;
    unsigned int upID_;
    unsigned int attributes_;
    Ratio ratio_points_;
    Ratio ratio_speed_;
    Game& game_;
    Coordinate coordinate_;

    //--------------------------------------------------------------------------
    // Copy Constructor
    Tower(const Tower& source);

    //--------------------------------------------------------------------------
    // Private assignment operator
    Tower& operator=(const Tower& original);
    bool operator!=(const Tower& tower);
    bool operator==(const Tower& tower);
    friend std::ostream& operator<<(std::ostream& out, const Tower& rhs);

  public:

//-------------------------------------------------------------------------- 
// Constructor
    Tower(unsigned int id, std::string name, unsigned int damage, unsigned int range,
          unsigned int costs, unsigned int upID, unsigned int attr, 
          Ratio ratio_speed, Game& game);

//--------------------------------------------------------------------------
// Destructor

    virtual ~Tower();

//--------------------------------------------------------------------------
// Getter

    const unsigned int getCosts() const;

    const unsigned int getID() const;

    const unsigned int getUpID() const;

    const unsigned int getAttributes() const;

    const std::string getName() const;

    const unsigned int getDamage() const;

    const unsigned int getRange() const;

    const Ratio getSpeedRatio() const;

    const Ratio getPointsRatio() const;

    const Coordinate getCoordinate() const;

    const bool canShoot() const;
//--------------------------------------------------------------------------
// Setter
//
    void setCosts( unsigned int costs );

    void setID( unsigned int id );

    void setUpID(unsigned upID);

    void setAttributes( unsigned int attributes );

    void setName( std::string name );

    void setDamage ( unsigned int damage );

    void setRange ( unsigned int range);

    void setSpeedRatio ( Ratio& ratio );

    void setPointsRatio ( Ratio& ratio );

    void setCoordinate(Coordinate c);
    //--------------------------------------------------------------------------
    // Calculates when Tower f��res
    // @return Tick Tower fires
    unsigned int fire();

    void incFirePoints();
    void decFirePoints();
    Monster* tryRange( std::vector<Monster*>& monsters);

};


#endif //TOWER_H
