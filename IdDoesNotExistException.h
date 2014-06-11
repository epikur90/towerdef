//------------------------------------------------------------------------------
/// Filename: IdDoesNotExistException.h
/// Description: TODO
/// Authors: Tutors
/// Group: 00 Tutor all
/// Latest Change: 15.04.2011
//------------------------------------------------------------------------------


#ifndef IdDoesNotExistEXCEPTION_H_
#define IdDoesNotExistEXCEPTION_H_

#include "CorruptionException.h"

class IdDoesNotExistException: public CorruptionException
{
  public:
    IdDoesNotExistException() throw();
    virtual ~IdDoesNotExistException() throw();
};

#endif // IdDoesNotExistEXCEPTION_H_