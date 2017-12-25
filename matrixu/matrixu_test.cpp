#include "matrixU.h"
#include <iostream>

int main()
{
	MatrixU mat;
	cout << "MatrixU mat: " << "(Row = " << mat.Row_() << " and Col = " << mat.Col_() << ')' << endl;
	cout << mat << endl;
	MatrixU mat2(3, 4);
	cout << "MatrixU mat2(3, 4):" << endl;
	cout << mat2 << endl;
	mat2.At(0, 0) = 111;
	mat2.At(1, 1) = 222;
	mat2.At(2, 2) = 333;
	mat2.At(2, 3) = 666;
	cout << "MatrixU mat2(3, 4):" << endl;
	cout << mat2 << endl;
	const MatrixU matConst(mat2);
	cout << "matConst.At(2, 2) = " << matConst.At(2, 2) << endl;
	MatrixU mat3(mat2);
	cout << "MatrixU mat3(mat2):" << endl;
	cout << mat3 << endl;
	MatrixU mat4(3,2);
	mat4.At(0, 1) = -2;
	mat4.At(1, 0) = 33;
	mat4.At(2, 1) = -123;
	cout << "mat4:" << endl;
	cout << mat4 << endl;
	mat3 = mat4;
	cout << "mat3=mat4" << endl;
	cout << mat3 << endl;
	cout << "mat3 == mat4 is " << (mat3 == mat4) << endl;
	mat3.At(0, 0) = 9;
	cout << "mat3.At(0, 0) = 9; "  << endl;
	cout << mat3 << endl;
	cout << "mat3 == mat4 is " << (mat3 == mat4) << endl;
	cout << "mat4:" << endl;
	cout << mat4 << endl;
	mat4.resize(4, 5);
	cout << "mat4.resize(4, 5):" << endl;
	cout << mat4 << endl;
	mat4.resize(2, 2);
	cout << "mat4.resize(2, 2):" << endl;
	cout << mat4 << endl;

	MatrixU matp(2, 3);
	matp.At(0, 0) = 1;
	matp.At(1, 1) = 2;
	matp.At(1, 2) = 3;
	matp.At(0, 1) = 6;
	cout << "matp:" << endl;
	cout << matp << endl;
	MatrixU matp2(2, 3);
	matp2.At(0, 0) = 1;
	matp2.At(1, 1) = 1;
	matp2.At(1, 2) = 1;
	matp2.At(1, 2) = 1;
	matp2.At(1, 0) = 1;
	cout << "matp2:" << endl;
	cout << matp2 << endl;
	matp = matp + matp2;
	cout << "matp + matp2:" << endl;
	cout << matp << endl;
	matp = matp - matp2;
	cout << "matp - matp2:" << endl;
	cout << matp << endl;

	try
	{
		MatrixU mat7(-1, 1);
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
		int n = mat2.At(0, -1);
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
		matp = matp - mat2;
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
		matp = matp + mat2;
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
}