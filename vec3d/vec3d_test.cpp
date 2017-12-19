#include "vec3d.h"

#include <iostream>
#include <sstream>

bool testParse(const std::string& str);

int main()
{
	using namespace std;
	Vec3d a;
	Vec3d b(5, 3, 4);
	Vec3d c(3, 0, 4);
	cout << "c=" << c << endl;
	double lc = c.Lenght();
	cout << "lc=" << lc << endl;
	testParse("{8.9,9,1}");
	testParse("{8.9, 9,1}");
	testParse("{8.9, 9 }");
	testParse("{8.9,9,1");
	cout << "a=" << a << endl;
	a = b;
	bool p = a == b;
	cout << "a==b ->" << p << endl;
	p = a != b;
	cout << "a!=b ->" << p << endl;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	c = a + b;
	cout << "a+b=" << c << endl;
	a += b;
	cout << "a+=b -> a=" << a << endl;
	c = a - b;
	cout << "a-b=" << c << endl;
	a -= b;
	cout << "a-=b -> a=" << a << endl;
	c = a * 3;
	cout << "a*3=" << c << endl;
	c = 3 * a;
	cout << "3*a=" << c << endl;
	a *= 3;
	cout << "a*=3 -> a=" << a << endl;
	c = a / 3;
	cout << "a/3=" << c << endl;
	a /= 3;
	cout << "a/=3 -> a=" << a << endl;
	a = Vec3d(1, 2, 0);
	b = Vec3d(4, 8, 0);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	double sc = Vec3d::Scal(a, b);
	cout << "Scal a*b -> " << sc << endl; /*скалярное произведение*/
	a = Vec3d(1, 2, 3);
	b = Vec3d(2, 1, -2);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	c = Vec3d::Vect(a, b);                         /*векторное произведение*/
	cout << "Vect a*b -> " << c << endl;
	
	return 0;
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