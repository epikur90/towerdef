//------------------------------------------------------------------------------
// Game.h
//
// study assistant Jörg Müller
// Authors: Manuel Papst    1130635
//          Stefan Janisch  0831181
//          Daniel Moser    0831423
//
//------------------------------------------------------------------------------
//
 
#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Tower.h"
#include "Monster.h"

class Tower;
class Monster;
class Db;
class Map;
class Spawn;

class Game
{

  private:

    //--------------------------------------------------------------------------
    // Private Class Members

    std::vector<uint> death_note_;

    Db* db_;
    unsigned int map_id_;
    unsigned int hp_;
    unsigned int cash_;
    //--------------------------------------------------------------------------
    // Tick Counter for the Current Tick/Round

    unsigned int tick_counter_;

    //--------------------------------------------------------------------------
    // vector to store Monsters
  
    std::vector<Monster*> monsters_;
    std::vector<Monster*> spawned_monsters_;

    //--------------------------------------------------------------------------
    // vector to store Towers
  
    std::vector<Tower*> towers_;
    std::vector<Tower*> built_towers_;

    //--------------------------------------------------------------------------
    // Private copy constructor

    Game( const Game& source );

    //--------------------------------------------------------------------------
    // Private assignment operator

    Game& operator=(const Game& original);

  public:

    //--------------------------------------------------------------------------
    // Constructors

    Game();

    //--------------------------------------------------------------------------
    // Destructor

    virtual ~Game();

    //--------------------------------------------------------------------------
    // Getter Methods
    const bool isWin() const;
    const unsigned int getCurrentTick() const;
    Db* getDb() const;
    const unsigned int getCash() const;
    const unsigned int getWidth() const;
    const unsigned int getHeight() const;
    const unsigned int getHP() const;
    const unsigned int getMapID() const;

    const std::vector<Monster*> getMonsters() const;
    const std::vector<Monster*> getSpawnedMonsters() const;
    const std::vector<Tower*> getTowers() const;
    const std::vector<Tower*> getBuiltTowers() const;
    const std::vector<Spawn*> getBuiltSpawns() const;

    //--------------------------------------------------------------------------
    // Setter Methods
    void incTick();
    void setTickCounter(unsigned int tick_counter); 
    void setDb(Db* db);
    void setMapID(unsigned int id);
    void setHP(unsigned int id);
    void setCash(unsigned int id);
    void addToDeathNote(uint id);
    void executeDeathNote();

    bool spawn();
    void killMonster(uint id);
    //--------------------------------------------------------------------------
    // Adds a Tower to the Gase
    // @param tower Tower to be added
    //

    void buildTower( Tower *tower );

    //--------------------------------------------------------------------------
    // Adds a Monster to the Gase
    // @param monster Monster to be added
    //

    void addMonster ( Monster *monster );


    //--------------------------------------------------------------------------
    // Runs the game
    // @return 0 when game is over
    //

    int run();



};

#endif //GAME_H
