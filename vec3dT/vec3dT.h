#ifndef  VEC3DT_H
#define VEC3DT_H

#include <iostream>
#include <sstream>

template <typename T> 
struct Vec3dT
{
public:
	Vec3dT() = default;
	Vec3dT& operator=(const Vec3dT& rhs) = default;
	Vec3dT(const T& xV, const T& yV, const T& zV);
	~Vec3dT() = default;

	bool operator ==(const Vec3dT<T>& rhs);
	bool compareTo(const Vec3dT<T>& rhs);
	bool operator !=(const Vec3dT& rhs);
	Vec3dT& operator+=(const Vec3dT& rhs);
	Vec3dT& operator-=(const Vec3dT& rhs);
	Vec3dT& operator*=(const double rhs);
	Vec3dT& operator/=(const double rhs);
	static double Scal(const Vec3dT& a, const Vec3dT& b); /*скалырное произведение*/
	static Vec3dT Vect(const Vec3dT& a, const Vec3dT& b); /*векторное произведение*/
	double Lenght();

	std::ostream& writeTo(std::ostream& ostrm)const;
	std::istream& readFrom(std::istream& istrm);

public:
	T x{ T() };
	T y{ T() };
	T z{ T() };

	double epsilon = 0.000000000001;
	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};

template<typename T>
Vec3dT<T> operator+(const Vec3dT <T>& lhs, const Vec3dT <T>& rhs);
template<typename T>
Vec3dT<T> operator-(const Vec3dT <T>& lhs, const Vec3dT <T>& rhs); 
template<typename T>
Vec3dT<T> operator*(const Vec3dT <T>& lhs, double rhs);
template<typename T>
Vec3dT<T> operator*(double lhs, const Vec3dT<T>& rhs);
template<typename T>
Vec3dT<T> operator/(const Vec3dT<T>& lhs, double rhs);

template<typename T>
std::ostream&operator<<(std::ostream& ostrm, const Vec3dT <T>& rhs);
template<typename T>
std::istream&operator>> (std::istream& istrm, Vec3dT <T>& rhs);
template<typename T>
bool testParse(const std::string& str);

template<typename T>
Vec3dT<T>::Vec3dT(const T& xV, const T& yV, const T& zV)
	: x(xV)
	, y(yV)
	, z(zV)
{

}

template <typename T>
bool Vec3dT<T>::operator==(const Vec3dT<T>& rhs) 
{
	return compareTo(rhs);
}

template <typename T>
bool Vec3dT<T>::compareTo(const Vec3dT<T>& rhs)
{
	return ((x == rhs.x) && (y == rhs.y) && (z == rhs.z));
}

bool Vec3dT<double>::compareTo(const Vec3dT<double>& rhs)
{
	return ((x - rhs.x) < epsilon && (y - rhs.y) < epsilon && (z - rhs.z) < epsilon);
}

bool Vec3dT<float>::compareTo(const Vec3dT<float>& rhs)
{
	return ((x - rhs.x) < epsilon && (y - rhs.y) < epsilon && (z - rhs.z) < epsilon);
}

template<typename T>
bool Vec3dT<T> :: operator!=(const Vec3dT& rhs)
{
	return !operator==(rhs);
}

template<typename T>
Vec3dT<T>& Vec3dT<T>:: operator+=(const Vec3dT& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}
template<typename T>
Vec3dT<T>& Vec3dT<T>:: operator-=(const Vec3dT& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

template<typename T>
Vec3dT<T>& Vec3dT<T>:: operator*=(const double rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}

template<typename T>
Vec3dT<T>& Vec3dT<T>:: operator/=(const double rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	return *this;
}

template<typename T>
double Vec3dT<T>::Lenght()
{
	return sqrt(x*x + y*y + z*z);
}

template<typename T>
double Vec3dT<T>::Scal(const Vec3dT& a, const Vec3dT& b) /*скалярное произведение*/
{
	return (a.x*b.x + a.y*b.y + a.z*b.z);
}

template<typename T>
Vec3dT<T> Vec3dT<T>::Vect(const Vec3dT& a, const Vec3dT& b) /*векторное произведение*/
{
	return Vec3dT(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

template<typename T>
Vec3dT<T> operator+(const Vec3dT <T>& lhs, const Vec3dT <T>& rhs)
{
	Vec3dT<T> sum = lhs;
	sum += rhs;
	return sum;
}

template<typename T>
Vec3dT<T> operator-(const Vec3dT <T>& lhs, const Vec3dT <T>& rhs)
{
	Vec3dT<T> sum (lhs);
	sum -= rhs;
	return sum;
}

template<typename T>
Vec3dT<T> operator*(const Vec3dT <T>& lhs, double rhs)
{
	Vec3dT<T> itog(lhs);
	itog *= rhs;
	return itog;
}

template<typename T>
Vec3dT<T> operator*(double lhs, const Vec3dT<T>& rhs)
{
	Vec3dT<T> itog(rhs);
	itog *= lhs;
	return itog;
}

template<typename T>
Vec3dT<T> operator/(const Vec3dT<T>& lhs, double rhs)
{
	Vec3dT<T> itog(lhs);
	itog /= rhs;
	return itog;
}


template<typename T>
std::ostream&operator<<(std::ostream& ostrm, const Vec3dT <T>& rhs)
{
	return rhs.writeTo(ostrm);
}

template<typename T>
std::istream&operator>> (std::istream& istrm, Vec3dT <T>& rhs)
{
	return rhs.readFrom(istrm);
}

template<typename T>
std::ostream& Vec3dT<T>::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << x << separator << y << separator << z << rightBrace;
	return ostrm;
}

template<typename T>
std::istream& Vec3dT<T>::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	T x_(0.0);
	char comma1(0);
	T y_(0.0);
	char comma2(0);
	T z_(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> x_ >> comma1 >> y_ >> comma2 >> z_ >> rightBrace;
	if (istrm.good())
	{
		if ((Vec3dT::leftBrace == leftBrace) && (Vec3dT::separator == comma1) && (Vec3dT::separator == comma2) && (Vec3dT::rightBrace == rightBrace))
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

//template<typename T>
//bool testParse(const std::string& str)
//{
//	using namespace std;
//	istringstream istrm(str);
//	Vec3dT<T> z;
//	istrm >> z;
//	if (istrm.good())
//	{
//		cout << "Read success: " << str << "->" << z << endl;
//	}
//	else
//	{
//		cout << "Read error  : " << str << "->" << z << endl;
//	}
//	return istrm.good();
//}
#endif