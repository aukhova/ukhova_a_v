#include <iostream>
#include <sstream>
#include <iostream>
#include <sstream>
#include "vec3d.h"

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

bool Vec3d :: operator !=(const Vec3d& rhs) const
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

Vec3d& Vec3d::operator*=(const Vec3d& rhs) /*��������� ������������*/
{
	Vec3d itog(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);
	*this = itog;
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

//Vec3d operator*( Vec3d& lhs,  Vec3d& rhs) /*��������� ������������*/
//{
//	Vec3d itog(lhs);
//	itog *= rhs;
//	return itog;
//}

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

double operator*(const Vec3d& a, const Vec3d& b) /*��������� ������������*/
{
	return (a.x*b.x + a.y*b.y + a.z*b.z);
}

inline std::ostream& operator<<(std::ostream& ostrm, const Vec3d& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Vec3d& rhs)
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

bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Vec3d z;
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