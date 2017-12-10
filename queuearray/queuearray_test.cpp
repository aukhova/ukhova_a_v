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
	cout << "x:" << x << endl;
	cout << "Top: " << x.Top() << endl;
	x.Push(15);
	x.Push(20);
	x.Push(36);
	cout << "x:" << x << endl;
	x.Pop();
	x.Pop();
	cout << "x:" << x << endl;
	QueueArray z;
	z = x;
	cout << "z:" << z << endl;
	/*y.~QueueArray();
	cout << "y(x)~:" << y << endl;*/

	/*system("pause");*/
	return 0;
}