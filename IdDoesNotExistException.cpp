//------------------------------------------------------------------------------
/// Filename: IdDoesNotExistException.cpp
/// Description: TODO
/// Authors: Tutors
/// Group: 00 Tutor all
/// Latest Change: 15.04.2011
//------------------------------------------------------------------------------


#include "IdDoesNotExistException.h"

IdDoesNotExistException::IdDoesNotExistException() throw() 
: CorruptionException("Error: Level file corrupt! ID does not exist!",6)
{
}

IdDoesNotExistException::~IdDoesNotExistException() throw()
{
}