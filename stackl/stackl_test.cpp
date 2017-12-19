#include "stackL.h"
#include <iostream>

using namespace std;

int main()
{
	StackL x;
	x.Push(1);
	x.Push(2);
	x.Push(3);
	cout << "Stack x:" << endl;
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
	x.Clear();
	cout << "IsEmpty after Clear: " << x.isEmpty() << endl;
	z = y;
	cout << "Stack z=y:" << endl;
	cout << z << endl;
	y.Top() = 25;
	cout << "Change top: " << y.Top() << endl;
	cout << "Stack y:" << endl;
	cout << y << endl;

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