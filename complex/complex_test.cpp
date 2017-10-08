#include <iostream>
#include <sstream>
#include "complex.h"

int main()
{
	using namespace std;
	Complex z;
	Complex m;
	cout << "z=" << z << endl;
	z = Complex(8.0);
	cout << "z= Complex(8.0) -> z=" << z << endl;
	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9, 9 }");
	testParse("{8.9,9");
	Complex a(1, -5);
	Complex b(5, 2);
	m = z + 5;
	cout << "z+5 -> m=" << m << endl;
	m = 5+z;
	cout << "5+z -> m=" << m << endl;
	m = z + Complex(5);
	cout << "z+Complex(5) -> m=" << m << endl;
	m = z;
	m+= Complex (5);
	cout << "z+= Complex (5) -> m=" << m << endl;
	z += 5;
	cout << "z+= 5 -> z=" << z << endl;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	m = a*b;
	cout << "a*b -> m=" << m << endl;
	a *= b;
	cout << "a *= b -> a=" << a << endl;
	m = a * 2;
	cout << "a*2 -> m=" << m << endl;
	m = 2*a;
	cout << "2*a -> m=" << m << endl;
	a *= 2;
	cout << "a *= 2 -> a=" << a << endl;
	m = a-2;
	cout << "a-2 -> m=" << m << endl;
	m = a - Complex(2);
	cout << "a-Complex(2) -> m=" << m << endl;
	a -= 2;
	cout << "a-= 2 -> a=" << a << endl;
	a -= b;
	cout << "a-=b -> a=" << a << endl;
	m = 7 - Complex(2);
	cout << "7 - Complex(2) -> m=" << m << endl;
	
	bool p(z == b);
	cout << "z == b"<<"->"<<p<<endl;
	p=(z != b);
	cout << "z != a" << "->" << p << endl;
	a = b;
	cout << "a == b" << "->" << p << endl;
	system("pause");
	return 0;
}