//------------------------------------------------------------------------------
/// Filename: InvalidCoordException.h
/// Description: TODO
/// Authors: Tutors
/// Group: 00 Tutor all
/// Latest Change: 15.04.2011
//------------------------------------------------------------------------------


#ifndef InvalidCoordEXCEPTION_H_
#define InvalidCoordEXCEPTION_H_

#include "CorruptionException.h"

class InvalidCoordException: public CorruptionException
{
  public:
    InvalidCoordException() throw();
    virtual ~InvalidCoordException() throw();
};

#endif // InvalidCoordEXCEPTION_H_