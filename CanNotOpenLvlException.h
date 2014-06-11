//------------------------------------------------------------------------------
/// Filename: CanNotOpenLvlException.h
/// Description: TODO
/// Authors: Tutors
/// Group: 00 Tutor all
/// Latest Change: 15.04.2011
//------------------------------------------------------------------------------


#ifndef CanNotOpenLvlEXCEPTION_H_
#define CanNotOpenLvlEXCEPTION_H_

#include "CorruptionException.h"

class CanNotOpenLvlException: public CorruptionException
{
  public:
    CanNotOpenLvlException() throw();
    virtual ~CanNotOpenLvlException() throw();
};

#endif // CanNotOpenLvlEXCEPTION_H_