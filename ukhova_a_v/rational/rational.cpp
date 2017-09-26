#include <iostream>
#include <sstream>
#include "rational.h"

Rational::Rational(const int chislt, const int znamn)
	:chisl(chislt)
	,znam(znamn)
{
	if (0 == znamn)
	{
		chisl = 0;
		znam = 0;
	}
}
Rational::Rational(const int chislt)
	: Rational(chislt, 1)
{

}
int Rational::NOD(const int chislt, const int znamn)
{
	int a = abs(chislt), b = abs(znamn);
	while (a != 0 && b != 0) {
		if (a >= b)
			a = a%b;
		else
			b = b%a;
	}
	return a + b;
}

//void Rational::reduce()
//{
//	int nod = NOD(chisl, znam);
//	chisl = chisl / nod;
//	znam = znam / nod;
//}

void Rational::norm()
{
	int nod = NOD(chisl, znam);
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

bool Rational :: operator !=(const Rational& rhs) const
{
	return !operator==(rhs);
}

Rational& Rational:: operator+=(const Rational& rhs)
{
	Rational a(chisl*rhs.znam + znam*rhs.chisl, znam*rhs.znam);
	a.norm();
	*this= a;
	return *this;

}

Rational& Rational:: operator+=(const int rhs)
{
	return operator+=(Rational(rhs));
}

Rational& Rational:: operator-=(const Rational& rhs)
{
	Rational a(chisl*rhs.znam - znam*rhs.chisl, znam*rhs.znam);
	a.norm();
	*this = a;
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
	Rational a = *this;
	a.norm();
	*this = a;
	return *this;
}

Rational& Rational:: operator*=(const int rhs)
{
	return operator*=(Rational(rhs));
}

Rational& Rational:: operator/=(const Rational& rhs)
{
	if (rhs.chisl == 0)
	{
		chisl = 0;
		znam = 0;
	}
	chisl *= rhs.znam;
	znam *= rhs.chisl;
	Rational a = *this;
	a.norm();
	*this = a;
	return *this;
}

Rational& Rational:: operator/=(const int rhs)
{
	return operator/=(Rational(rhs));
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
	ostrm << chisl << separator << znam;
	return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	int chislitel(0);
	char slesh(0);
	int znamenatel(0);
	char rightBrace(0);
	istrm >> leftBrace>> chislitel >> slesh >> znamenatel>> rightBrace;
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

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Rational& rhs)
{
	return rhs.readFrom(istrm);
}

bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Rational z;
	istrm >> z;
	if (istrm.good())
	{
		cout << "Read success: " << str << "->" << z << endl;
	}
	else
	{
		cout << "Read error  : " << str << "->" << z << endl;
	}
	return istrm.good();
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
	Rational sum(lhs);
	sum += rhs;
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

Rational operator*(const Rational& lhs, const Rational& rhs)
{
	Rational itog(lhs);
	itog *= rhs;
	itog.norm();
	return itog;
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
	Rational itog(lhs);
	itog /= rhs;
	itog.norm();
	return itog;
}

Rational& Rational:: operator=(const int rhs)
{
	*this = Rational(rhs);
	return *this;

}