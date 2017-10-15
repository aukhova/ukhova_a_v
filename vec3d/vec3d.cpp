#include "vec3d.h"

#include <iostream>
#include <sstream>

Vec3d::Vec3d(const double x_, const double y_, const double z_)
	:x(x_)
	, y(y_)
	, z(z_)
{

}

bool Vec3d ::  operator==(const Vec3d& rhs) const
{
	return ((abs(x - rhs.x)<epsilon) && (abs(y - rhs.y)<epsilon) && (abs(z - rhs.z)<epsilon));
}

bool Vec3d :: operator!=(const Vec3d& rhs) const
{
	return !operator==(rhs);
}

Vec3d& Vec3d:: operator+=(const Vec3d& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

Vec3d& Vec3d:: operator-=(const Vec3d& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

Vec3d& Vec3d::operator*=(const double rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}

Vec3d& Vec3d::operator/=(const double rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	return *this;
}

Vec3d operator+(const Vec3d& lhs, const Vec3d& rhs)
{
	Vec3d sum(lhs);
	sum += rhs;
	return sum;
}

Vec3d operator-(const Vec3d& lhs, const Vec3d& rhs)
{
	Vec3d itog(lhs);
	itog -= rhs;
	return itog;
}

Vec3d operator*(const Vec3d& lhs, double rhs)
{
	Vec3d itog(lhs);
	itog *= rhs;
	return itog;
}

Vec3d operator*(double lhs, const Vec3d& rhs)
{
	Vec3d itog(rhs);
	itog *= lhs;
	return itog;
}

Vec3d operator/(const Vec3d& lhs, double rhs)
{
	Vec3d itog(lhs);
	itog /= rhs;
	return itog;
}

double Vec3d::Lenght()
{
	return sqrt(x*x + y*y + z*z);
}

double Vec3d::Scal(const Vec3d& a, const Vec3d& b) /*скалярное произведение*/
{
	return (a.x*b.x + a.y*b.y + a.z*b.z);
}

Vec3d Vec3d::Vect(const Vec3d& a, const Vec3d& b) /*векторное произведение*/
{
	return Vec3d(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

std::ostream& operator<<(std::ostream& ostrm, const Vec3d& rhs)
{
	return rhs.writeTo(ostrm);
}

std::istream& operator >> (std::istream& istrm, Vec3d& rhs)
{
	return rhs.readFrom(istrm);
}

std::ostream& Vec3d::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << x << separator << y << separator << z << rightBrace;
	return ostrm;
}

std::istream& Vec3d::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	double x_(0.0);
	char comma1(0);
	double y_(0.0);
	char comma2(0);
	double z_(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> x_ >> comma1 >> y_ >> comma2 >> z_ >> rightBrace;
	if (istrm.good())
	{
		if ((Vec3d::leftBrace == leftBrace) && (Vec3d::separator == comma1) && (Vec3d::separator == comma2) && (Vec3d::rightBrace == rightBrace))
		{
			x = x_;
			y = y_;
			z = z_;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}