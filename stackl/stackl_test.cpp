#include "stackL.h"
#include <iostream>

using namespace std;

int main()
{
	StackL x;
	cout << "StackL x:" << endl;
	cout << x << endl;
	x.Push(1);
	x.Push(2);
	x.Push(3);
	x.Push(4);
	cout << "Stack x after push:" << endl;
	cout << x << endl;
	x.Pop();
	cout << "Stack after pop:" << endl;
	cout << x << endl;
	cout << "IsEmpty: " << x.isEmpty() << endl;
	StackL y(x);
	cout << "Stack y(x):" << endl;
	cout << y << endl;
	StackL z;
	cout << "Stack z:" << endl;
	cout << z << endl;
	z.Push(3);
	x.Clear();
	cout << "x after Clear: " << x << endl;
	cout << "x IsEmpty after Clear: " << x.isEmpty() << endl;
	y.Top() = 25;
	cout << "y.Top() = 25 : " << y.Top() << endl;
	cout << "Stack y:" << endl;
	cout << y << endl;
	z = y;
	cout << "Stack z=y:" << endl;
	cout << z << endl;
	z = x;
	cout << "Stack z=x:" << endl;
	cout << z << endl;
	z.Clear();
	cout << "z.Clear()" << endl;
	z = y;
	cout << "Stack z=y:" << endl;
	cout << z << endl;

	try
	{
		x.Top();
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

	try
	{
		x.Pop();
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
};