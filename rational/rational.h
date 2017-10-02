#ifndef  RATIONAL_H
#define RATIONAL_H
#include <iosfwd>
#include <iostream>
#include <sstream>
 class Rational
{
public:
	Rational() {};
	Rational(const int chislt, const int znamn);
	Rational(const int chislt);
	int NOD(const int chislt, const int znamn);
	/*void reduce();*/
	void norm();
	bool operator ==(const Rational& rhs)const;
	bool operator !=(const Rational& rhs)const;
	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const int rhs);
	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const int rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const int rhs);
	Rational& operator/=(const Rational& rhs);
	Rational& operator/=(const int rhs);
	Rational& operator=(const int rhs);
	std::ostream& writeTo(std::ostream& ostrm)const;
	std::istream& readFrom(std::istream& istrm);
	int chisl;
	int znam;
	static const char leftBrace{ '(' };
	static const char separator{ '/' };
	static const char rightBrace{ ')' };
};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator+(const Rational& lhs, const int rhs);
Rational operator+(const int lhs, const Rational& rhs);

Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const int rhs);
Rational operator-(const int lhs, const Rational& rhs);

Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const int rhs);
Rational operator*(const int lhs, const Rational& rhs);


Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const int rhs);
Rational operator/(const int lhs, const Rational& rhs);

inline std::ostream&operator<<(std::ostream& ostrm, const Rational& rhs);

inline std::istream&operator >> (std::istream& istrm, Rational& rhs);

bool testParse(const std::string& str);

#endif