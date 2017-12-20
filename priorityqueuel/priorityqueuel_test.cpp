#include "priorityqueuel.h"
#include <iostream>

using namespace std;

int main()
{
	PriorityQueueL x;
	x.Push(1);
	x.Push(2);
	x.Push(3);
	cout << "x:"<< x << endl;
	PriorityQueueL y(x);
	cout << "y(x):" << y << endl;
	y.~PriorityQueueL();
	cout << "y(x):" << y << endl;
	x.Pop();
	cout << "x:" << x << endl;
	cout << "Top: " << x.Top() << endl;
	
	x.Pop();
	cout << "x:" << x << endl;
	x.Pop();
	cout << "x:" << x << endl;
	y.Push(5);
	y.Push(4);
	y.Push(2);
	cout << "y:" << y << endl;
	y.PushPr(3);
	cout << "y:" << y << endl;
	y.PushPr(11);
	cout << "y:" << y << endl;
	y.PushPr(15);
	cout << "y:" << y << endl;
	y.PushPr(12);
	cout << "y:" << y << endl;
	y.PushPr(0);
	cout << "y:" << y << endl;
	y.PushPr(7);
	cout << "y:" << y << endl;

	PriorityQueueL z;
	z.Push(1);
	z.Push(2);
	z.Push(3);
	cout << "z:" << z << endl;
	z = y;
	cout << "z=y:" << z << endl;

	return 0;
}