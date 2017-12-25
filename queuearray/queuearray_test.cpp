#include "queuearray.h"
#include<iostream>

using namespace std;

int main()
{
	QueueArray x;
	x.Push(1);
	x.Push(2);
	x.Push(3);
	cout << "x:" << x << endl;
	QueueArray y(x);
	cout << "y(x):" << y << endl;
	x.Pop();
	cout << "x.Pop():" << x << endl;
	cout << "x.Top(): " << x.Top() << endl;
	x.Push(15);
	x.Push(20);
	x.Push(36);
	cout << "x:" << x << endl;
	x.Pop();
	x.Pop();
	cout << "y:" << y << endl;
	cout << "x:" << x << endl;
	y = x;
	cout << "y = x :" << y << endl;
	QueueArray z;
	cout << "z:" << z << endl;
	y = z;
	cout << "y = z:" << y << endl;
	z = x;
	cout << "z = x:" << z << endl;
	
	return 0;
}