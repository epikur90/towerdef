#ifndef DB_H_
#define DB_H_
#include <vector>
#include <string>
#include "FileIO.h"


class Monster;
class Tower;
class Game;
class Map;
class Spawn;
class Coordinate;

class Db
{
  private:
    std::vector<Monster*> monsters_;
    std::vector<Tower*> towers_;
    std::vector<Map*> maps_;
    std::vector<Spawn*> spawns_;
    unsigned int cash_;
    unsigned int width_;
    unsigned int height_;
    unsigned int hp_;
    unsigned int lvl_check_;
    Game& game_;
    FileIO fio_;
    std::vector<uint> delete_list_
    ;
    void clear();
    bool towerIdExists(unsigned int id) const;
    bool mapIdExists(unsigned int id) const;
    bool validateMaps() const;
    bool validateCoords(Coordinate coord, uint map_id) const;
  public:
    bool monsterIdExists(unsigned int id) const;
    Db(Game& game, std::string lvl_file, std::string db_file);
    virtual ~Db();

    Monster* getMonster(unsigned int id) const;
    Tower* getTower(unsigned int id) const;
    Map* getMap(unsigned int id) const;
    unsigned int getMonsterCount() const;
    unsigned int getTowerCount() const;
    unsigned int getMapCount() const;
    const std::vector<Tower*> getTowers() const;
    const std::vector<Monster*> getMonsters() const;
    std::vector<Spawn*>* getSpawns() ;
    const unsigned int getCash() const;
    const unsigned int getWidth() const;
    const unsigned int getHeight() const;
    const unsigned int getHP() const;

    unsigned int addMonster(Monster* monster);
    unsigned int addTower(Tower* attack);
    unsigned int addMap(Map* map);
    unsigned int addSpawn(Spawn* spawn);
    void addToDeleteList(uint id);
    void executeDeleteList();
    void deleteSpawn(uint id);
    void incLvlCheck();

    void corruptionCheck();

    int findTowerByID(uint id);

    const void debugList() const;

};
#endif // DB_H_
