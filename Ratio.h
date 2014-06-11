#ifndef RATIO_H
#define RATIO_H

#include<iostream>

class Ratio
{
private:
  unsigned int numerator_;
  unsigned int denominator_;

public:
  Ratio();
  Ratio(unsigned int numerator, unsigned int denominator);
  ~Ratio();

  Ratio operator+(const int &number);
  Ratio operator+(const Ratio &number);
  Ratio operator-(const int &number);
  bool operator==(const Ratio &ratio);

  friend std::ostream& operator<<(std::ostream& out, const Ratio& r);


  const unsigned int getNumerator() const;
  const unsigned int getDenominator() const;
  void setNumerator(unsigned int numerator);
  void setDenominator(unsigned int denominator);
};
#endif // RATIO_H
