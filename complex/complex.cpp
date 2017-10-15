#include "complex.h"

#include <iostream>
#include <sstream>

bool Complex ::  operator==(const Complex& rhs) const
{
	return (std::abs(re - rhs.re) < epsilon) && (std::abs(im - rhs.im) < epsilon);
}

bool Complex :: operator!=(const Complex& rhs) const
{
	return !operator==(rhs);
}

Complex& Complex:: operator+=(const double rhs)
{
	return operator+=(Complex(rhs));
}

Complex& Complex:: operator-=(const double rhs)
{
	return operator-=(Complex(rhs));
}

std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
	return rhs.writeTo(ostrm);
}

std::istream& operator >> (std::istream& istrm, Complex& rhs)
{
	return rhs.readFrom(istrm);
}

Complex::Complex(const double real)
	:Complex(real, 0.0)
{

}

Complex::Complex(const double real, const double imaginary)
	: re(real)
	, im(imaginary)
{

}

Complex& Complex :: operator+=(const Complex& rhs)
{
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex& Complex :: operator-=(const Complex& rhs)
{
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

Complex& Complex:: operator*=(const Complex& rhs)
{
	Complex mult;
	mult.re = re*rhs.re - im*rhs.im;
	mult.im = re*rhs.im + im*rhs.re;
	*this = mult;
	return *this;
}

Complex& Complex:: operator*=(const double rhs)
{
	re *= rhs;
	im *= rhs;
	return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex sum(lhs);
	sum += rhs;
	return sum;
}

Complex operator+(const Complex& lhs, const double rhs)
{
	Complex sum(lhs);
	sum += rhs;
	return sum;
}

Complex operator+(const double lhs, const Complex& rhs)
{
	Complex sum(rhs);
	sum += lhs;
	return sum;
}

Complex operator-(const Complex& lhs, const double rhs)
{
	Complex itog(lhs);
	itog -= rhs;
	return itog;
}

Complex operator-(const double lhs, const Complex& rhs)
{
	Complex itog = Complex(lhs);
	itog -= rhs;
	return itog;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
	return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
	Complex itog(lhs);
	itog *= rhs;
	return itog;
}

Complex operator*(const Complex& lhs, const double rhs)
{
	Complex itog(lhs);
	itog *= rhs;
	return itog;
}

Complex operator*(const double lhs, const Complex& rhs)
{
	Complex itog(rhs);
	itog *= lhs;
	return itog;
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaganary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
	if (istrm.good())
	{
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) && (Complex::rightBrace == rightBrace))
		{
			re = real;
			im = imaganary;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}