#include "array.h"
#include <iostream>

int main()
{
	Array n;
	cout << "Array n: " << n << ' ';;
	cout << "n.size(): " << n.size() << endl;
	cout << "n.lenth(): " << n.lenth() << endl;
	cout << endl;
	Array n2(2);
	cout << "Array n2(2): " << n2 << ' ';;
	cout << "n2.size(): " << n2.size() << endl;
	cout << "n2.lenth(): " << n2.lenth() << endl;
	n2.Add(5);
	n2.Add(1);
	n2.Add(3);
	cout << "Array n2 with elements: " << n2 << endl;
	cout << "n2.size(): " << n2.size() << endl;
	cout << "n2.lenth(): " << n2.lenth() << endl;
	cout << endl;
	n2.Add(2, 2);
	cout << "n2.Add(2, 2): " << n2 << endl;
	cout << "Sn2.size(): " << n2.size() << endl;
	cout << "n2.lenth(): " << n2.lenth() << endl;
	cout << "n2[0]: " << n2[0] << endl;
	cout << endl;
	Array N2(n2);
	cout << "N2(n2): " << N2 << endl;
	cout << "N2.size(): " << N2.size() << endl;
	cout << "N2.lenth(): " << N2.lenth() << endl;
	cout << endl;
	Array NN = N2;
	cout << "NN = N2: " << NN << endl;
	cout << "NN.size(): " << NN.size() << endl;
	cout << "NN.lenth(): " << NN.lenth() << endl;
	Array Np;
	cout << "Np: " << Np << endl;
	cout << "Np.size(): " << Np.size() << endl;
	cout << "Np.lenth(): " << Np.lenth() << endl;
	cout << endl;
	Np = N2;
	cout << "Np = N2: " << Np << endl;
	cout << "Np.size(): " << Np.size() << endl;
	cout << "Np.lenth(): " << Np.lenth() << endl;
	cout << endl;
	Array Np2;
	cout << "Np2: " << Np2 << endl;
	Np = Np2;
	cout << "Np = Np2: " << Np << endl;
	cout << "Np.size(): " << Np.size() << endl;
	cout << "Np.lenth(): " << Np.lenth() << endl;
	cout << endl;
	NN.remove(0);
	cout << "NN.remove(0): " << NN << endl;
	cout << "NN.size(): " << NN.size() << endl;
	cout << "NN.lenth(): " << NN.lenth() << endl;
	cout << endl;
	//N2.~Array();
	//cout << "N2: " << N2 << endl;


	cout << "Array error1(-5): " << endl;
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

	cout << "Array error2(0): " << endl;
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

	cout << "n2[-4]:" << endl;
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

	cout << "n2[5]:" << endl;
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

	cout << "n2.Add(5,5):" << endl;
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

	cout << "n2.Add(5, -5):" << endl;
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


	cout << "n2.remove(5):" << endl;
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

	cout << "n2.remove(4):" << endl;
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

	cout << "n2.remove(-5):" << endl;
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


	return 0;
};