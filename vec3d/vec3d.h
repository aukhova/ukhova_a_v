#ifndef  VEC3D_H
#define VEC3D_H
#include <iosfwd>
#include <iostream>
#include <sstream>#pragma once

struct Vec3d
{
public:
	Vec3d() = default;
	Vec3d& operator=(const Vec3d& rhs) = default;
	Vec3d(const double x_, const double y_, const double z_);
	bool operator ==(const Vec3d& rhs)const;
	bool operator !=(const Vec3d& rhs)const;
	Vec3d& operator+=(const Vec3d& rhs);
	Vec3d& operator-=(const Vec3d& rhs);
	Vec3d& operator*= (const double rhs);
	Vec3d& operator*=(const Vec3d& rhs); /*векторное произведение*/
	Vec3d& operator/= (const double rhs);
	double Lenght();
	~Vec3d() = default;

	std::ostream& writeTo(std::ostream& ostrm)const;
	std::istream& readFrom(std::istream& istrm);

public:
	double x{ 0.0 };
	double y{ 0.0 };
	double z{ 0.0 };

	double epsilon = 0.000000000001;
	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};

Vec3d operator+(const Vec3d& lhs, const Vec3d& rhs);
Vec3d operator-(const Vec3d& lhs, const Vec3d& rhs);
Vec3d operator*(const Vec3d& lhs, double rhs);
Vec3d operator*(double lhs, const Vec3d& rhs);
//Vec3d operator*( Vec3d& lhs,  Vec3d& rhs);  /*векторное произведение*/
double operator*(const Vec3d& lhs, const Vec3d& rhs); /*скалырное произведение*/
Vec3d operator/(const Vec3d& lhs, double rhs);

inline std::ostream&operator<<(std::ostream& ostrm, const Vec3d& rhs);
inline std::istream&operator >> (std::istream& istrm, Vec3d& rhs);
bool testParse(const std::string& str);

#endif