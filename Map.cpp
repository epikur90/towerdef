//------------------------------------------------------------------------------
/// Filename: Map.cpp
/// Description: TODO
/// Authors: Tutors
/// Group: 00 Tutor all
/// Latest Change: 15.04.2011
//------------------------------------------------------------------------------

#include "Map.h"
#include "Coordinate.h"
#include<iostream>

Map::Map(unsigned int id, unsigned int width, unsigned int height, 
	 	std::vector<Coordinate*> fields)
		: id_(id), width_(width), height_(height), fields_(fields)
{
}

//------------------------------------------------------------------------------
Map::~Map()
{
}
//------------------------------------------------------------------------------
const unsigned int Map::getID() const
{
	return id_;
}
//------------------------------------------------------------------------------
const unsigned int Map::getWidth() const
{
	return width_;
}
//------------------------------------------------------------------------------
const unsigned int Map::getHeight() const
{
	return height_;
}
//------------------------------------------------------------------------------
const std::vector<Coordinate*> Map::getFields() const
{
	return fields_;
}
//------------------------------------------------------------------------------
Coordinate* Map::getNorthCoord(Coordinate c)
{
	for(uint curs=0; curs < fields_.size(); curs++)
	{
		if(fields_.at(curs)->getX() == c.getX()
		&& fields_.at(curs)->getY() == c.getY()-1)
		{
			return fields_.at(curs);
		}		
	}
	return 0;		
}
//------------------------------------------------------------------------------
Coordinate* Map::getEastCoord(Coordinate c)
{
	for(uint curs=0; curs < fields_.size(); curs++)
	{
		if(fields_.at(curs)->getX() == c.getX()+1
		&& fields_.at(curs)->getY() == c.getY())
		{
			return fields_.at(curs);
		}		
	}
	return 0;		
}
//------------------------------------------------------------------------------
Coordinate* Map::getSouthCoord(Coordinate c)
{
	for(uint curs=0; curs < fields_.size(); curs++)
	{
		if(fields_.at(curs)->getX() == c.getX()
		&& fields_.at(curs)->getY() == c.getY()+1)
		{
			return fields_.at(curs);
		}		
	}
	return 0;		
}
//------------------------------------------------------------------------------
Coordinate* Map::getWestCoord(Coordinate c)
{
	for(uint curs=0; curs < fields_.size(); curs++)
	{
		if(fields_.at(curs)->getX() == c.getX()-1
		&& fields_.at(curs)->getY() == c.getY())
		{
			return fields_.at(curs);
		}		
	}
	return 0;		
}
//------------------------------------------------------------------------------
Coordinate* Map::at(int x, int y) 
{
	for(uint curs=0; curs < width_; curs++)
	{
		if(fields_.at(curs)->getX() == x
		&& fields_.at(curs)->getY() == y)
		{
			return fields_.at(curs);
		}
	}
	return 0;
}