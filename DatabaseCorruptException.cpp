//------------------------------------------------------------------------------
/// Filename: DatabaseCorruptException.cpp
/// Description: TODO
/// Authors: Tutors
/// Group: 00 Tutor all
/// Latest Change: 15.04.2011
//------------------------------------------------------------------------------


#include "DatabaseCorruptException.h"

DatabaseCorruptException::DatabaseCorruptException() throw() 
	: CorruptionException("Error: Database file corrupt!",4)
{
}

DatabaseCorruptException::~DatabaseCorruptException() throw()
{
}
