//------------------------------------------------------------------------------
// Monster.h
//
// study assistant Jörg Müller
// Authors: Manuel Papst    1130635
//          Stefan Janisch  0831181
//          Daniel Moser    0831423
//
//------------------------------------------------------------------------------
//

#ifndef MONSTER_H
#define MONSTER_H

class Game;
class Ratio;
class Coordinate;

class Monster
{

  private:

    //--------------------------------------------------------------------------
    // Private Class Members

    unsigned int id_;
    std::string name_;
    unsigned int damage_;
    unsigned int hp_;
    unsigned int reward_;
    Ratio ratio_speed_;  
    Ratio ratio_points_;
    Game& game_;
    Coordinate coordinate_;
    uint last_dir_;
    //--------------------------------------------------------------------------
    // Copy Constructor
    Monster(const Monster& source);

    //--------------------------------------------------------------------------
    // Private assignment operator
    Monster& operator=(const Monster& original);
    friend std::ostream& operator<<(std::ostream& out, const Monster& m);
  
  public:

    //--------------------------------------------------------------------------
    // Constructor
    Monster(unsigned int id, std::string name, unsigned int damage, unsigned int hp,
        unsigned int reward, Ratio ratio, Game& game);

    //--------------------------------------------------------------------------
    // Destructor
    virtual ~Monster();

    bool hit(uint damage);
    bool action();
    void move(uint dir);
    bool attack();

    //--------------------------------------------------------------------------
    // Getter
    const unsigned int getID() const;
    const std::string getName() const;
    const unsigned int getDamage() const;
    const unsigned int getHP() const;
    const unsigned int getReward() const;
    const Ratio getRatioSpeed() const;
    const Ratio getRatioPoints() const;    
    const Coordinate getCoordinate() const;    
    const bool isAlive() const;    
    const bool canMove() const;    

    //--------------------------------------------------------------------------
    // Setter
    void setID(unsigned int id);
    void setName(std::string name);
    void setDamage ( unsigned int damage );
    void setHP( unsigned int health_points);
    void setReward( unsigned int reward );    
    void setRatioSpeed ( Ratio& ratio_speed );
    void setRatioPoints ( Ratio& ratio_points );
    void setCoordinate ( Coordinate& c );
    void incMovePoints();
    void decMovePoints();


};

#endif //MONSTER_H
