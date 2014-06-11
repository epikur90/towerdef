//------------------------------------------------------------------------------
/// Filename: FileIO.h
/// Description: TODO
/// Authors: Tutors
/// Group: 00 Tutor all
/// Latest Change: 15.04.2011
//------------------------------------------------------------------------------


#ifndef FileIO_H_
#define FileIO_H_

#include <fstream>
#include <string>

class Db;
class Game;
class Ratio;
class Monster;
class Tower;
class Map;
class Spawn;
class Coordinate;

class FileIO
{
  private:
    Db& db_;
    Game& game_;
    std::string lvl_filename_;
    std::string db_filename_;

    bool checkHeader(std::ifstream& binary);
    int  getChunkType(std::ifstream& binary);

    Tower* readTower(std::ifstream& bin, unsigned int id);
    Monster* readMonster(std::ifstream& bin, unsigned int id);
    Map* readMap(std::ifstream& bin, unsigned int id);
    bool readLevel(std::ifstream& bin);
    Spawn* readSpawn(std::ifstream& bin, unsigned int id);

  public:
    FileIO(Db& db, Game& game);
    FileIO(Db& db, Game& game, 
        std::string lvl_filename, std::string db_filename);
    virtual ~FileIO();

    void readDbFile();
    void readLvlFile();
    bool readData(std::ifstream& bin, char* data, 
        unsigned int count);
    bool readData(std::ifstream& bin, char& data);
    bool readData(std::ifstream& bin, unsigned int& data);
    bool readData(std::ifstream& bin, bool& data);
    bool readData(std::ifstream& bin, Ratio& data);
    bool readData(std::ifstream& bin, Coordinate& data);
};

#endif // FileIO_H_
