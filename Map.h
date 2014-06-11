//------------------------------------------------------------------------------
// Filename: Map.h
// Description: Class representing a general Map
// Authors: Tutors
// Tutor: Tutors
// Group: 42
// Created: 08.08.2011
// Last change: 02.09.2011
//------------------------------------------------------------------------------
 
#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include<iostream>
#include<vector>

class Coordinate;

class Map
{
  private:
    //--------------------------------------------------------------------------
    // Private copy constructor

    Map(const Map& original);

    //--------------------------------------------------------------------------
    // Private assignment operator

    Map& operator=(const Map& original);
    
    //--------------------------------------------------------------------------
    unsigned int id_;
    unsigned int width_;
    unsigned int height_;
    std::vector<Coordinate*> fields_;
  public:
    //--------------------------------------------------------------------------
    // Consturctor

    Map(unsigned int id, unsigned int width, unsigned int height, std::vector<Coordinate*> fields);

    //--------------------------------------------------------------------------
    // Destructor

    virtual ~Map();
  
    //--------------------------------------------------------------------------
    // Getter Methods
    const unsigned int getID() const;
    const unsigned int getWidth() const;
    const unsigned int getHeight() const;
    const std::vector<Coordinate*> getFields() const;
    Coordinate* getNorthCoord(Coordinate c);
    Coordinate* getEastCoord(Coordinate c);
    Coordinate* getSouthCoord(Coordinate c);
    Coordinate* getWestCoord(Coordinate c);
    Coordinate* at(int x, int y);
};

#endif //MAP_H_INCLUDE
