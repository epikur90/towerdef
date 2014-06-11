//------------------------------------------------------------------------------
/// Filename: LevelCorruptException.h
/// Description: TODO
/// Authors: Tutors
/// Group: 00 Tutor all
/// Latest Change: 15.04.2011
//------------------------------------------------------------------------------


#ifndef LEVELCORRUPTEXCEPTION_H_
#define LEVELCORRUPTEXCEPTION_H_

#include "CorruptionException.h"

class LevelCorruptException: public CorruptionException
{
  public:
    LevelCorruptException() throw();
    virtual ~LevelCorruptException() throw();
};

#endif // LEVELCORRUPTEXCEPTION_H_