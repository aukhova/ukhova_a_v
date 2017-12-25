#include "priorityqueuel.h"
#include <iostream>

using namespace std;

int main()
{
	PriorityQueueL x;
	x.PushPr(1);
	x.PushPr(2);
	x.PushPr(3);
	cout << "x:"<< x << endl;
	PriorityQueueL p(x);
	cout << "p(x):" << p << endl;
	PriorityQueueL y;
	cout << "y:" << y << endl;
	x.Pop();
	cout << "x:" << x << endl;
	cout << "Top: " << x.Top() << endl;
	
	x.Pop();
	cout << "x:" << x << endl;
	x.Pop();
	cout << "x:" << x << endl;
	y.PushPr(5);
	y.PushPr(4);
	y.PushPr(2);
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
	cout << endl;

	PriorityQueueL z;
	z.PushPr(1);
	z.PushPr(3);
	z.PushPr(2);
	cout << "z:" << z << endl;
	cout << endl;
	z = y;
	cout << "z=y:" << z << endl;

	PriorityQueueL z2;
	cout << "z2:" << z2 << endl;
	cout << endl;
	z = z2;
	cout << "z=z2:" << z << endl;
	cout << endl;
	z = y;
	cout << "z=y:" << z << endl;

	return 0;
}