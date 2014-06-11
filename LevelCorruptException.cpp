//------------------------------------------------------------------------------
/// Filename: LevelCorruptException.cpp
/// Description: TODO
/// Authors: Tutors
/// Group: 00 Tutor all
/// Latest Change: 15.04.2011
//------------------------------------------------------------------------------


#include "LevelCorruptException.h"

LevelCorruptException::LevelCorruptException() throw() 
: CorruptionException("Error: Level file corrupt!",5)
{
}

LevelCorruptException::~LevelCorruptException() throw()
{
}