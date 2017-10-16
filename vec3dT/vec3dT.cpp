#include "vec3dT.h"

int main()
{
	using namespace std;

	Vec3dT<double> a;
	Vec3dT<double> b(5, 3, 4);
	Vec3dT<double> c(3, 0, 4);
	cout << "c=" << c << endl;
	double lc = c.Lenght();
	cout << "lc=" << lc << endl;
	/*testParse("{8.9,9,1}");
	testParse("{8.9, 9,1}");
	testParse("{8.9, 9 }");
	testParse("{8.9,9,1");*/
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
	c = 3.0 * a;
	cout << "3*a=" << c << endl;
	a *= 3;
	cout << "a*=3 -> a=" << a << endl;
	c = a / 3.0;
	cout << "a/3=" << c << endl;
	a /= 3;
	cout << "a/=3 -> a=" << a << endl;
	a = Vec3dT<double>(1, 2, 0);
	b = Vec3dT<double>(4, 8, 0);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	double sc = Vec3dT<double>::Scal(a, b);
	cout << "Scal a*b -> " << sc << endl; /*скалярное произведение*/
	a = Vec3dT<double>(1, 2, 3);
	b = Vec3dT<double>(2, 1, -2);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	c = Vec3dT<double>::Vect(a, b);                         /*векторное произведение*/
	cout << "Vect a*b -> " << c << endl;
	system("pause");

	return 0;
}


