#include "Ratio.h"
#include<iostream>


const unsigned int Ratio::getNumerator() const
{
  return numerator_;
}
//-----------------------------------------------------------------------------
//
const unsigned int Ratio::getDenominator() const
{
  return denominator_;
}
//-----------------------------------------------------------------------------
//
void Ratio::setNumerator(unsigned int numerator)
{
  numerator_ = numerator;
}
//-----------------------------------------------------------------------------
//
void Ratio::setDenominator(unsigned int denominator)
{
  denominator_ = denominator;
}
//-----------------------------------------------------------------------------
//
Ratio::Ratio()
{
  numerator_ = 0;
  denominator_ = 0;
}
//-----------------------------------------------------------------------------
//
Ratio::Ratio(unsigned int numerator, unsigned int denominator)
{
  numerator_ = numerator;
  denominator_ = denominator;
}
//-----------------------------------------------------------------------------
//
Ratio::~Ratio()
{
}
//-----------------------------------------------------------------------------
//
Ratio Ratio::operator +(const int &number)
{
  Ratio result;
  int numerator;
  numerator = denominator_ * number;
  result.setNumerator(numerator_ + numerator);
  result.setDenominator(denominator_);
  return result;
}
//-----------------------------------------------------------------------------
//
Ratio Ratio::operator +(const Ratio &other)
{
  Ratio result;
  result.setNumerator((numerator_ * other.getDenominator()) + (denominator_ * other.getNumerator()) );
  result.setDenominator(denominator_ * other.getDenominator());
  return result;
}
//-----------------------------------------------------------------------------
//
Ratio Ratio::operator -(const int &number)
{
  Ratio result;
  int numerator;
  numerator = denominator_ * number;
  result.setNumerator(numerator_ - numerator);
  result.setDenominator(denominator_);
  return result;
}
//-----------------------------------------------------------------------------
//
bool Ratio::operator ==(const Ratio& ratio)
{
  if(numerator_ == ratio.getNumerator() && denominator_ == ratio.getDenominator())
    return true;
  return false;
}
//-----------------------------------------------------------------------------
//
std::ostream& operator <<(std::ostream& out, const Ratio& r)
{
  out << r.getNumerator() << " / " << r.getDenominator();
  return out;
}
