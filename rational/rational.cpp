#include "rational.h"

#include <iostream>
#include <sstream>

using namespace std;

Rational::Rational(const int chislt, const int znamn)
	: chisl(chislt)
	, znam(znamn)
{
	if (0 == znamn)
	{
		throw invalid_argument("Error: Znam can't be = 0");
	}
}

Rational::Rational(const int chislt)
	: Rational(chislt, 1)
{

}

void Rational::norm()
{
	int a = abs(chisl), b = abs(znam);
	while (a != 0 && b != 0) 
	{
		if (a >= b)
			a = a%b;
		else
			b = b%a;
	}
	int nod=a + b;
	chisl = chisl / nod;
	znam = znam / nod;
	if (znam < 0)
	{
		chisl = -chisl;
		znam = -znam;
	}
}

bool Rational ::  operator==(const Rational& rhs) const
{
	return (chisl == rhs.chisl) && (znam == rhs.znam);
}

bool Rational :: operator!=(const Rational& rhs) const
{
	return !operator==(rhs);
}

Rational& Rational:: operator+=(const Rational& rhs)
{
	chisl = chisl*rhs.znam + znam*rhs.chisl;
	znam = znam*rhs.znam;
	(*this).norm();
	return *this;

}

Rational& Rational:: operator+=(const int rhs)
{
	return operator+=(Rational(rhs));
}

Rational& Rational:: operator-=(const Rational& rhs)
{
	chisl = chisl*rhs.znam - znam*rhs.chisl;
	znam = znam*rhs.znam;
	(*this).norm();
	return *this;

}

Rational& Rational:: operator-=(const int rhs)
{
	return operator-=(Rational(rhs));
}

Rational& Rational:: operator*=(const Rational& rhs)
{
	chisl *= rhs.chisl;
	znam *= rhs.znam;
	(*this).norm();
	return *this;
}

Rational& Rational:: operator*=(const int rhs)
{
	return operator*=(Rational(rhs));
}

Rational& Rational:: operator/=(const Rational& rhs)
{
	if (0 == rhs.chisl)
	{
		throw invalid_argument("Error: Nelza /0");
	}
	else {
		chisl *= rhs.znam;
		znam *= rhs.chisl;
		(*this).norm();
		return *this;
	}
}

Rational& Rational:: operator/=(const int rhs)
{
	if (0 == rhs)
	{
		throw invalid_argument("Error: Nelza /0");
	}
	else
	return operator/=(Rational(rhs));
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
	if (znam == 1) {
		ostrm << chisl;
	} else {
		ostrm << chisl << separator << znam;
	}
	return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	int chislitel(0);
	char slesh(0);
	int znamenatel(0);
	char rightBrace(0);
	istrm >> leftBrace >> chislitel >> slesh >> znamenatel >> rightBrace;
	if (istrm.good())
	{
		if ((Rational::leftBrace == leftBrace) && (Rational::separator == slesh) && (Rational::rightBrace == rightBrace))
		{
			chisl = chislitel;
			znam = znamenatel;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
	return rhs.writeTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Rational& rhs)
{
	return rhs.readFrom(istrm);
}



Rational operator+(const Rational& lhs, const Rational& rhs)
{
	Rational sum(lhs);
	sum += rhs;
	sum.norm();
	return sum;
}

Rational operator+(const Rational& lhs, const int rhs)
{
	Rational sum(lhs);
	sum += rhs;
	sum.norm();
	return sum;
}

Rational operator+(const int lhs, const Rational& rhs)
{
	Rational sum(rhs);
	sum += lhs;
	sum.norm();
	return sum;
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
	Rational itog(lhs);
	itog -= rhs;
	itog.norm();
	return itog;
}

Rational operator-(const Rational& lhs, const int rhs)
{
	Rational itog(lhs);
	itog -= rhs;
	itog.norm();
	return itog;
}

Rational operator-(const int lhs, const Rational& rhs)
{
	Rational itog = Rational(lhs);
	itog -= rhs;
	itog.norm();
	return itog;
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
	Rational itog(lhs);
	itog *= rhs;
	itog.norm();
	return itog;
}

Rational operator*(const Rational& lhs, const int rhs)
{
	Rational itog(lhs);
	itog *= rhs;
	itog.norm();
	return itog;
}

Rational operator*(const int lhs, const Rational& rhs)
{
	Rational itog(rhs);
	itog *= lhs;
	itog.norm();
	return itog;
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
	if (0 == rhs.chisl)
	{
		throw invalid_argument("Error: Nelza /0");
	}
	else {
		Rational itog(lhs);
		itog /= rhs;
		itog.norm();
		return itog;
	}
}

Rational operator/(const Rational& lhs, const int rhs)
{
	if (0 == rhs)
	{
		throw invalid_argument("Error: Nelza /0");
	}
	else {
		Rational itog(lhs);
		itog /= rhs;
		itog.norm();
		return itog;
	}
}

Rational operator/(const int lhs, const Rational& rhs)
{
	if (0 == rhs.chisl)
	{
		throw invalid_argument("Error: Nelza /0");
	}
	else {
		Rational itog = Rational(lhs);
		itog /= rhs;
		itog.norm();
		return itog;
	}
}

Rational& Rational:: operator=(const int rhs)
{
	*this = Rational(rhs);
	return *this;

}