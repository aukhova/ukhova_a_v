#include <iostream>
#include <sstream>
#include "complex.h"

int main()
{
	using namespace std;
	Complex z;
	cout << "z=" << z << endl;
	z += Complex(8.0);
	cout << "z += Complex(8.0) -> z=" << z << endl;
	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9, 9 }");
	testParse("{8.9,9");
	Complex a(1, -5);
	Complex b(5, 2);
	z += 5;
	cout << "z+= 5 -> z=" << z << endl;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	a *= b;
	cout << "a *= b -> a=" << a << endl;
	a *= 2;
	cout << "a *= 2 -> a=" << a << endl;
	a -= 2;
	cout << "a-= 2 -> a=" << a << endl;
	a -= b;
	cout << "a-=b -> a=" << a << endl;
	Complex c = a + b;
	cout << "a+b -> " << c << endl;
	c = a - b;
	cout << "a-b -> " << c << endl;
	bool p(z == b);
	cout << "z == b"<<"->"<<p<<endl;
	p=(z != b);
	cout << "z != a" << "->" << p << endl;
	a = b;
	cout << "a == b" << "->" << p << endl;
	system("pause");
	return 0;
}