//------------------------------------------------------------------------------
/// Filename: DatabaseCorruptException.h
/// Description: TODO
/// Authors: Tutors
/// Group: 00 Tutor all
/// Latest Change: 15.04.2011
//------------------------------------------------------------------------------


#ifndef DATABASECORRUPTEXCEPTION_H_
#define DATABASECORRUPTEXCEPTION_H_

#include "CorruptionException.h"

class DatabaseCorruptException: public CorruptionException
{
  public:
    DatabaseCorruptException() throw();
    virtual ~DatabaseCorruptException() throw();
};

#endif // DATABASECORRUPTEXCEPTION_H_