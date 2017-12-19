#include "matrixU.h"
#include <iostream>

int main()
{
	MatrixU mat;
	cout << "Constructor without params: " << "(Row = " << mat.Row_() << " and Col = " << mat.Col_() << ')' << endl;
	cout << mat;
	MatrixU mat2(3, 4);
	mat2.At(0, 0) = 111;
	mat2.At(1, 1) = 222;
	mat2.At(2, 2) = 333;
	mat2.At(2, 3) = 666;
	cout << "Constructor with params and add some elements:" << endl;
	cout << mat2;
	const MatrixU matConst(mat2);
	cout << "element from const MatrixU = " << matConst.At(2, 2) << endl;
	matConst.~MatrixU();
	cout << matConst << endl;
	MatrixU mat3(mat2);
	cout << "Copy constructor:" << endl;
	cout << mat3;
	MatrixU mat4(3,2);
	mat4.At(0, 1) = -2;
	mat4.At(1, 0) = 33;
	mat4.At(2, 1) = -123;
	cout << "m4at:" << endl;
	cout << mat4;
	mat3 = mat4;
	cout << "mat3=mat4" << endl;
	cout << mat3 << endl;
	cout << "mat3 == mat4 is " << (mat3 == mat4) << endl;
	mat3.At(0, 0) = 9;
	cout << "mat3 == mat4 is " << (mat3 == mat4) << endl;
	cout << "mat4:" << endl;
	cout << mat4;
	mat4.resize(4, 5);
	cout << "after resize(4, 5):" << endl;
	cout << mat4;
	mat4.resize(2, 2);
	cout << "after resize(2, 2):" << endl;
	cout << mat4;
	return 0;
}