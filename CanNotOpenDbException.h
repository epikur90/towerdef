//------------------------------------------------------------------------------
/// Filename: CanNotOpenDbException.h
/// Description: TODO
/// Authors: Tutors
/// Group: 00 Tutor all
/// Latest Change: 15.04.2011
//------------------------------------------------------------------------------


#ifndef CanNotOpenDbEXCEPTION_H_
#define CanNotOpenDbEXCEPTION_H_

#include "CorruptionException.h"

class CanNotOpenDbException: public CorruptionException
{
  public:
    CanNotOpenDbException() throw();
    virtual ~CanNotOpenDbException() throw();
};

#endif // CanNotOpenDbEXCEPTION_H_