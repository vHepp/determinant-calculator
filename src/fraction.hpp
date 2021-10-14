#include <cstdint>

#ifndef _FRACTION_H
#define _FRACTION_H

#include <iostream>

class Fraction {
	public:
  		Fraction(int32_t n=0,int32_t d=1);
  		~Fraction(void) { }

  		Fraction operator=(Fraction rhs);

  		Fraction operator+(Fraction rhs);
  		Fraction operator-(Fraction rhs);
  		Fraction operator*(Fraction rhs);
  		Fraction operator/(Fraction rhs);
  		Fraction operator=(int32_t rhs);

  		bool operator==(Fraction rhs);
  		bool operator!=(Fraction rhs);
  		bool operator<=(Fraction rhs);
  		bool operator>=(Fraction rhs);
  		bool operator<(Fraction rhs);
  		bool operator>(Fraction rhs);

  		int32_t getNum() { return num; }
  		int32_t getDen() { return den; }
		
		Fraction reciprocal();
  
  	private:
 		int
   			num,
   			den;
};

std::istream &operator>>(std::istream &,Fraction &);
std::ostream &operator<<(std::ostream &,Fraction);

#endif // _FRACTION_H
