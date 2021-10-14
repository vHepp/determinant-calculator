#include "fraction.hpp"

int32_t gcd(int32_t a,int32_t b) {
  int32_t
    r;

  if (a < 0)
    a = -a;
  if (b < 0)
    b = -b;

  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }

  return a;
}

Fraction::Fraction(int32_t n,int32_t d) {
  int
    g;

  if (d < 0) {
    n = -n;
    d = -d;
  }

  g = gcd(n,d);

  num = n / g;
  den = d / g;
}

Fraction Fraction::operator+(Fraction rhs) {
  int32_t
    s,	// temp numerator
    t;	// temp denominator

  s = num * rhs.den + den * rhs.num;
  t = den * rhs.den;

  return Fraction(s,t);
}

Fraction Fraction::operator=(int32_t rhs) {
  int32_t
    s,	// temp numerator
    t;	// temp denominator

  s = rhs;
  t = 1;

  return Fraction(s,t);
}

Fraction Fraction::operator-(Fraction rhs) {
  int32_t
    s,	// temp numerator
    t;	// temp denominator

  s = num * rhs.den - den * rhs.num;
  t = den * rhs.den;

  return Fraction(s,t);
}

Fraction Fraction::operator*(Fraction rhs) {
  int32_t
    s,	// temp numerator
    t;	// temp denominator

  s = num * rhs.num;
  t = den * rhs.den;

  return Fraction(s,t);
}

Fraction Fraction::operator/(Fraction rhs) {
  int32_t
    s,	// temp numerator
    t;	// temp denominator

  s = num * rhs.den;
  t = den * rhs.num;

  return Fraction(s,t);
}

Fraction Fraction::operator=(Fraction rhs) {

  num = rhs.num;
  den = rhs.den;

  return *this;
}

bool Fraction::operator==(Fraction rhs) {
  return num == rhs.num && den == rhs.den;
}

bool Fraction::operator!=(Fraction rhs) {
  return num != rhs.num || den != rhs.den;
}

bool Fraction::operator<(Fraction rhs) {
  return num * rhs.den < den * rhs.num;
}

bool Fraction::operator>(Fraction rhs) {
  return num * rhs.den > den * rhs.num;
}

bool Fraction::operator<=(Fraction rhs) {
  return num * rhs.den <= den * rhs.num;
}

bool Fraction::operator>=(Fraction rhs) {
  return num * rhs.den >= den * rhs.num;
}

Fraction Fraction::reciprocal() {
  return Fraction(den,num);
}

std::istream &operator>>(std::istream &is,Fraction &f) {
  int32_t
    n,d;
  char
    slash;

  is >> n >> slash >> d;

  f = Fraction(n,d);

  return is;
}

std::ostream &operator<<(std::ostream &os,Fraction f) {

  os << f.getNum() << " / " << f.getDen();

  return os;
}
