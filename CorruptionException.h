//------------------------------------------------------------------------------
/// Filename: CorruptionException.h
/// Description: TODO
/// Authors: Tutors
/// Group: 00 Tutor all
/// Latest Change: 15.04.2011
//------------------------------------------------------------------------------


#ifndef CorruptionException_H_
#define CorruptionException_H_

#include <exception>

class CorruptionException : public std::exception
{
  private:
    const char* what_;
    const unsigned int ret_;
  public:
    CorruptionException(const char* what, const unsigned int ret);
    virtual ~CorruptionException() throw();
    const char* what();
    const unsigned int ret() const;
    
};

#endif // CorruptionException_H_
