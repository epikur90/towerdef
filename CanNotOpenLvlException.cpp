//------------------------------------------------------------------------------
/// Filename: CanNotOpenLvlException.cpp
/// Description: TODO
/// Authors: Tutors
/// Group: 00 Tutor all
/// Latest Change: 15.04.2011
//------------------------------------------------------------------------------


#include "CanNotOpenLvlException.h"

CanNotOpenLvlException::CanNotOpenLvlException() throw() 
	: CorruptionException("Error: Level file cannot be opened!",3)
{
}

CanNotOpenLvlException::~CanNotOpenLvlException() throw()
{
}