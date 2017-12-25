#include "rational.h"

#include <iostream>
#include <sstream>


bool testParse(const std::string& str);

int main()
{
	using namespace std;
	Rational a(-5, -10);
	Rational b(9);
	Rational p;
	cout << "a(-5, -10)->a=" << a << endl;
	cout << " b(9)->b=" << b << endl;
	cout << " p->p=" << p << endl;
	a.norm();
	cout << "a.norm() -> a=" << a << endl;
	a += 9;
	cout << "a += 9 -> a=" << a << endl;
	a += b;
	cout << "a += b -> a=" << a << endl;
	a -= 0;
	cout << "a -= 0 -> a=" << a << endl;
	a -= Rational(1, 5);
	cout << "a -= Rational (1, 5) -> a=" << a << endl;
	p = a - Rational(5, -10);
	cout << "p=a- Rational (5, -10) -> p=" << p << endl;
	p = Rational(12, 10) - 1;
	cout << "p=Rational (12, 10) -1  -> p=" << p << endl;
	p = 1 - Rational(1, 10);
	cout << "p=1- Rational (1, 10) -> p=" << p << endl;
	p = b + Rational(1, 10);
	cout << "p=b+ Rational (1, 10) -> p=" << p << endl;
	p = Rational(1, 10) + 1;
	cout << "p=Rational (1, 10) +1  -> p=" << p << endl;
	p = 1 + Rational(1, 10);
	cout << "p=1+ Rational (1, 10) -> p=" << p << endl;
	b /= 3;
	cout << "b /=3 b=" << b << endl;
	a /= Rational(1, 3);
	cout << "a /= Rational(1, 3) a=" << a << endl;
	p = Rational(2, 7) / Rational(5, 7);
	cout << "p = Rational(2, 7) / Rational(5, 7) -> p=" << p << endl;
	p = Rational(2, 7) / 5;
	cout << "p = Rational(2, 7) / 5-> p=" << p << endl;
	p = 1 / Rational(2, 7);
	cout << "p = 1/Rational(2, 7)-> p=" << p << endl;
	a = 7;
	cout << "a=7 ->a=" << a << endl;
	a *= 5;
	cout << "a*=5 ->a=" << a << endl;
	a *= Rational(2, 7);
	cout << "a *= Rational(2, 7)-> a=" << a << endl;
	p = Rational(2, 7) * Rational(5, 7);
	cout << "p = Rational(2, 7) * Rational(5, 7) -> p=" << p << endl;
	p = Rational(2, 7) * 5;
	cout << "p = Rational(2, 7) * 5 -> p=" << p << endl;
	p = 5 * Rational(2, 7);
	cout << "p = 5*Rational(2, 7) -> p=" << p << endl;
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

	cout << "Rational error(-5,0): " <<  endl;
	try
	{
		Rational error(-5,0);
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	
	catch (...)
	{
		cout << "Unknown; try else:" << endl;
		throw;
	}

	cout << "b /= 0: " << endl;
	try
	{
		b /= 0;
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}

	catch (...)
	{
		cout << "Unknown; try else:" << endl;
		throw;
	}

	cout << "b /= Rational(0, 3): " << endl;
	try
	{
		b /= Rational(0, 3);
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}

	catch (...)
	{
		cout << "Unknown; try else:" << endl;
		throw;
	}

	cout << "p = Rational(2, 7) / Rational(0, 7): " << endl;
	try
	{
		p = Rational(2, 7) / Rational(0, 7);
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}

	catch (...)
	{
		cout << "Unknown; try else:" << endl;
		throw;
	}

	cout << "p = Rational(2, 7) / 0: " << endl;
	try
	{
		p = Rational(2, 7) / 0;
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}

	catch (...)
	{
		cout << "Unknown; try else:" << endl;
		throw;
	}

	cout << "p = 1/Rational(0, 7): " << endl;
	try
	{
		p = 1/Rational(0, 7);
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}

	catch (...)
	{
		cout << "Unknown; try else:" << endl;
		throw;
	}

	return 0;
}

bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Rational z;
	istrm >> z;
	if (istrm.good()) {
		cout << "Read success: " << str << "->" << z << endl;
	} else {
		cout << "Read error  : " << str << "->" << z << endl;
	}
	return istrm.good();
}