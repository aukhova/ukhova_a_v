#ifndef  RATIONAL_H
#define RATIONAL_H

#include <iosfwd>

class Rational
{
public:
	Rational() = default;
	Rational& operator=(const Rational& rhs) = default;
	Rational(const int chislt, const int znamn);
	Rational(const int chislt);
	~Rational() = default;

	bool operator==(const Rational& rhs)const;
	bool operator!=(const Rational& rhs)const;
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

public:
	int chisl{0};
	int znam{1};
	static const char leftBrace{ '(' };
	static const char separator{ '/' };
	static const char rightBrace{ ')' };

public:
	void norm();
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

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);

std::istream& operator>>(std::istream& istrm, Rational& rhs);


#endif