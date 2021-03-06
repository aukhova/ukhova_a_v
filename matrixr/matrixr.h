#ifndef MATRIXR_H
#define MATRIXR_H

#include <stddef.h>
#include <iosfwd>

using namespace std;

class MatrixR
{
public:
	MatrixR();
	MatrixR(const int row, const int col);
	MatrixR(const MatrixR& rhs);
	~MatrixR();
	MatrixR& operator=(const MatrixR& rhs);
	bool operator==(const MatrixR& rhs) const;
	bool operator!=(const MatrixR& rhs) const;
	int& At(const ptrdiff_t iRow, const ptrdiff_t iCol);
	const int& At(const ptrdiff_t iRow, const ptrdiff_t iCol) const;
	ostream& writeTo(std::ostream& ostrm) const;
	int lenth() const;
	MatrixR& resize(const ptrdiff_t r, const ptrdiff_t c);
	MatrixR operator*(const MatrixR& rhs) const;
private:
	const ptrdiff_t defaultRow_{ 3 };
	const ptrdiff_t defaultCol_{ 3 };
	ptrdiff_t nRow_{ 0 };
	ptrdiff_t nCol_{ 0 };
	int** pRows_{ nullptr };
	void swap(MatrixR& lhs, MatrixR& rhs);
};

ostream& operator<<(std::ostream& ostrm, const MatrixR& rhs);

#endif 