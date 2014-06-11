//------------------------------------------------------------------------------
/// Filename: CorruptionException.cpp
/// Description: TODO
/// Authors: Tutors
/// Group: 00 Tutor all
/// Latest Change: 15.04.2011
//------------------------------------------------------------------------------


#include "CorruptionException.h"

CorruptionException::CorruptionException(const char* what, const unsigned int ret) 
: what_(what), ret_(ret)
{
}
//------------------------------------------------------------------------------
CorruptionException::~CorruptionException() throw()
{
}
//------------------------------------------------------------------------------
const char* CorruptionException::what()
{
  return what_;
}
//------------------------------------------------------------------------------
const unsigned int CorruptionException::ret() const
{
  return ret_;
}