//------------------------------------------------------------------------------
/// Filename: InvalidCoordException.cpp
/// Description: TODO
/// Authors: Tutors
/// Group: 00 Tutor all
/// Latest Change: 15.04.2011
//------------------------------------------------------------------------------


#include "InvalidCoordException.h"

InvalidCoordException::InvalidCoordException() throw() 
: CorruptionException("Error: Level file corrupt! Coordinate invalid!",7)
{
}

InvalidCoordException::~InvalidCoordException() throw()
{
}