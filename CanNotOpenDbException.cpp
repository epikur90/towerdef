//------------------------------------------------------------------------------
/// Filename: CanNotOpenDbException.cpp
/// Description: TODO
/// Authors: Tutors
/// Group: 00 Tutor all
/// Latest Change: 15.04.2011
//------------------------------------------------------------------------------


#include "CanNotOpenDbException.h"

CanNotOpenDbException::CanNotOpenDbException() throw() 
	: CorruptionException("Error: Database file cannot be opened!",2)
{
}

CanNotOpenDbException::~CanNotOpenDbException() throw()
{
}