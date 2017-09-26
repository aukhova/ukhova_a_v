#include <iostream>
#include <sstream>
#include "rational.h"

int main()
{
	using namespace std;
	Rational a(-5, -10);
	Rational b(9);
	Rational p;
	cout <<"a="<< a << endl;
	cout << "b=" << b << endl;
	a.norm();
	cout <<"a.norm() -> a=" << a << endl;
	a += 9;
	cout << "a += 9 -> a=" << a << endl;
	a += b;
	cout << "a += b -> a=" << a << endl;
	a -= 0;
	cout << "a -= 0 -> a=" << a << endl;
	a -= Rational(1, 5);
	cout << "a -= Rational (1, 5) -> a=" << a << endl;
	p=a- Rational (5, -10);
	cout << "p=a- Rational (5, -10) -> p=" << p << endl;
	p = b + Rational(1, 10);
	cout << "p=b+ Rational (1, 10) -> p=" << p << endl;
	b /= 3;
	cout <<"b /=3 b="<<b << endl;
	a /= Rational(1, 3);
	cout <<"a /= Rational(0, 3) a="<< a << endl;
	p = Rational(2, 7) / Rational(5, 7);
	cout << "p = Rational(2, 7) / Rational(5, 7) -> p=" << p << endl;
	a = 7;
	cout <<"a=7 a="<< a << endl;
	a *= 5;
	cout << "a*=5 a=" << a << endl;
	a *= Rational(2, 7);
	cout << "a *= Rational(2, 7) a=" << a << endl;
	p= Rational(2, 7) * Rational(5, 7);
	cout << "p = Rational(2, 7) * Rational(5, 7) -> p=" << p << endl;
	bool t = p == a;
	cout << "p == a -> " << t << endl;
	t = a != b;
	cout << "a != b -> " << t << endl;
	a = Rational(2, 3);
	cout << "a=" << a << endl;
	testParse("(8/9)");
	testParse("(8/9");
	testParse("8/9)");
	testParse("(8 9)");
	testParse("(8  /9)");
	system("pause");
	return 0;
}