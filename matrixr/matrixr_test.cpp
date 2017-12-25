#include "matrixR.h"

#include <iostream>

int main()
{
	MatrixR mat0;
	cout << "MatrixR mat0 : " << endl;
	cout << mat0 << endl;
	MatrixR mat(2, 3);
	cout << "MatrixR mat(2, 3) : " << endl;
	cout << mat << endl;
	for (int i(0); i < 2 * 3; i++)
		mat.At(i / 3, i % 3) = i;
	cout << "mat : " << endl;
	cout << mat << endl;
	cout << mat.lenth() << endl;
	MatrixR mat2(3, 3);
	mat2.At(0, 0) = 10;
	mat2.At(0, 2) = 0;
	mat2.At(1, 0) = -2;
	mat2.At(1, 1) = 5;
	mat2.At(1, 2) = 6;
	cout << "mat2 : " << endl;
	cout << mat2 << endl;
	MatrixR mat3(1, 1);
	mat3 = mat2;
	cout << "mat3 = mat2 : " << endl;
	cout << mat3 << endl;
	MatrixR mat4(mat3);
	cout << "MatrixR mat4(mat3) : " << endl;
	cout << mat4 << endl;
	cout << "mat3 == mat4 is " << (mat3 == mat4) << endl;
	
	mat4.resize(4, 5);
	cout << "mat4.resize(4, 5):" << endl;
	cout << mat4;
	mat4.resize(1, 2);
	cout << "mat4.resize(1, 2):" << endl;
	cout << mat4;
	try
	{
		MatrixR mat2(-1, 1);
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
		int n = mat.At(0, -1);
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

	MatrixR mat5(3, 3);
	MatrixR mat6(3, 2);
	mat5.At(0, 0) = 2;
	mat5.At(0, 1) = 1;
	mat5.At(0, 2) = -8;
	mat5.At(1, 0) = 4;
	mat5.At(1, 1) = 5;
	mat5.At(1, 2) = -6;
	mat5.At(2, 0) = 0;
	mat5.At(2, 1) = 3;
	mat5.At(2, 2) = 10;
	mat6.At(0, 0) = 1;
	mat6.At(0, 1) = 0;
	mat6.At(1, 0) = -7;
	mat6.At(1, 1) = -1;
	mat6.At(2, 0) = 2;
	mat6.At(2, 1) = 5;
	cout << "mat5 : " << endl;
	cout << mat5 << endl;
	cout << "mat6 : " << endl;
	cout << mat6 << endl;
	cout << "mat5 * mat6:" << endl;
	cout << (mat5 * mat6) << endl;
	
	try
	{
		cout << (mat4 * mat6) << endl;
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