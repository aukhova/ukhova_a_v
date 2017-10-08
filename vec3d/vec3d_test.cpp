#include <iostream>
#include <sstream>
#include "vec3d.h"

int main()
{
	using namespace std;
	Vec3d a;
	Vec3d b(5, 3, 4);
	Vec3d c(3,0,4);
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
	double sc = a*b;
	cout << "скалярное произведение a*b -> " << sc << endl; /*скалярное произведение*/
	a = Vec3d(1, 2, 3);
	b = Vec3d(2, 1, -2);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	//c = a*b;                         /*векторное произведение*/
	//cout << "a*b -> " << c << endl;
	a *= b;                          /*векторное произведение*/
	cout << " векторное произведение a*=b -> a=" << a << endl;
	system("pause");
	return 0;
}