#include "array.h"
#include <iostream>

int main()
{
	Array n;
	cout << "Default constructor: " << n << ' ';;
	cout << "Size of default array: " << n.size() << endl;
	cout << "Capacity of default array: " << n.lenth() << endl;
	cout << endl;
	Array n2(2);
	n2.Add(5);
	n2.Add(1);
	n2.Add(3);
	cout << "Array with elements: " << n2 << endl;
	cout << "Size of array: " << n2.size() << endl;
	cout << "Capacity of array: " << n2.lenth() << endl;
	cout << endl;
	n2.Add(2, 2);
	cout << "Array with elements: " << n2 << endl;
	cout << "Size of array: " << n2.size() << endl;
	cout << "Capacity of array: " << n2.lenth() << endl;
	cout << endl;
	Array N2(n2);
	cout << "Array with elements: " << N2 << endl;
	cout << "Size of array: " << N2.size() << endl;
	cout << "Capacity of array: " << N2.lenth() << endl;
	cout << endl;
	Array NN = N2;
	cout << "Array with elements: " << NN << endl;
	cout << "Size of array: " << NN.size() << endl;
	cout << "Capacity of array: " << NN.lenth() << endl;
	cout << endl;
	NN.remove(0);
	cout << "Array with elements: " << NN << endl;
	cout << "Size of array: " << NN.size() << endl;
	cout << "Capacity of array: " << NN.lenth() << endl;
	cout << endl;

	try
	{
		Array error1(-5);
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	catch (length_error& e)
	{
		cout << e.what() << endl;
	}
	catch (out_of_range& e)
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
		Array error2(0);
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	catch (length_error& e)
	{
		cout << e.what() << endl;
	}
	catch (out_of_range& e)
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
		n2[4];
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	catch (length_error& e)
	{
		cout << e.what() << endl;
	}
	catch (out_of_range& e)
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
		n2[5];
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	catch (length_error& e)
	{
		cout << e.what() << endl;
	}
	catch (out_of_range& e)
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
		n2.Add(5,5);
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	catch (length_error& e)
	{
		cout << e.what() << endl;
	}
	catch (out_of_range& e)
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
		n2.Add(5, -5);
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	catch (length_error& e)
	{
		cout << e.what() << endl;
	}
	catch (out_of_range& e)
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
		n2.remove(5);
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	catch (length_error& e)
	{
		cout << e.what() << endl;
	}
	catch (out_of_range& e)
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
		n2.remove(4);
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	catch (length_error& e)
	{
		cout << e.what() << endl;
	}
	catch (out_of_range& e)
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
		n2.remove(-5);
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	catch (length_error& e)
	{
		cout << e.what() << endl;
	}
	catch (out_of_range& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown; try else:" << endl;
		throw;
	}

	system("pause");
	return 0;
};