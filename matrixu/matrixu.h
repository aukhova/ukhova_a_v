#ifndef MATRIXU_H
#define MATRIXU_H

#include <stddef.h>
#include <iosfwd>

using namespace std;

class MatrixU
{
public:
	MatrixU();
	MatrixU(const int row, const int col);
	MatrixU(const MatrixU& rhs);
	~MatrixU();
	MatrixU& operator=(const MatrixU& rhs);
	bool operator==(const MatrixU& rhs) const;
	bool operator!=(const MatrixU& rhs) const;
	int& At(const ptrdiff_t iRow, const ptrdiff_t iCol);
	const int& At(const ptrdiff_t iRow, const ptrdiff_t iCol) const;
	ostream& writeTo(std::ostream& ostrm) const;
	int Row_() const;
	int Col_() const;
	MatrixU& resize(const ptrdiff_t r, const ptrdiff_t c);
	MatrixU operator+(const MatrixU& rhs) ;
	MatrixU operator-(const MatrixU& rhs);
private:
	const ptrdiff_t defaultRow_{ 3 };
	const ptrdiff_t defaultCol_{ 3 };
	ptrdiff_t nRow_{ 0 };
	ptrdiff_t nCol_{ 0 };
	int* pData_{ nullptr };
	void swap(MatrixU& lhs, MatrixU& rhs);
};

ostream& operator<<(std::ostream& ostrm, const MatrixU& rhs);

#endif 