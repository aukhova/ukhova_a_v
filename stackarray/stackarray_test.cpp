#include "stackarray.h"
#include<iostream>

using namespace std;

int main()
{
	StackArray x;
	x.Push(1);
	x.Push(2);
	x.Push(3);
	cout << "Stack x:" << endl;
	cout << x << endl;
	x.Pop();
	cout << "x.Pop():" << endl;
	cout << x << endl;
	cout << "IsEmpty: " << x.isEmpty() << endl;
	StackArray y(x);
	cout << "Stack y(x):" << endl;
	cout << y << endl;
	StackArray z;
	cout << "Stack z:" << endl;
	cout << z << endl;
	z.Push(2);
	z.Push(3);
	cout << "Stack z:" << endl;
	cout << z << endl;
	x.Clear();
	cout << "IsEmpty after Clear: " << x.isEmpty() << endl;
	y.Top() = 25;
	cout << "Change top: " << y.Top() << endl;
	cout << "Stack y:" << endl;
	cout << y << endl;
	z = y;
	cout << "Stack z=y:" << endl;
	cout << z << endl;
	z = x;
	cout << "Stack z=x:" << endl;
	cout << z << endl;
	x = y;
	cout << "Stack x=y:" << endl;
	cout << x << endl;
	x.Clear();
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
}