#include "matrixU.h"
#include<iostream>
#include<sstream>
#include <stdexcept>

using namespace std;

MatrixU::MatrixU() :nRow_(defaultRow_), nCol_(defaultCol_), pData_(new int[defaultRow_ * defaultCol_]{ int() })
{
}

MatrixU::MatrixU(const int row, const int col) : nRow_(row), nCol_(col)
{
	if ((row <= 0) || (col <= 0)) throw invalid_argument("Error: Size can't be less or equals 0");
	pData_ = new int[nCol_*nRow_]{ int() };
}

MatrixU::MatrixU(const MatrixU& rhs) :nRow_(rhs.nRow_), nCol_(rhs.nCol_), pData_(new int[rhs.nRow_ * rhs.nCol_]{ int() })
{
	for (int j(0); j < nRow_; j++)
	{
		for (int i{ 0 }; i < nCol_; i++)
		{
			pData_[nCol_ * j + i] = rhs.pData_[nCol_ * j + i];
		}
	}
}

MatrixU::~MatrixU()
{
	if (!(pData_ == nullptr))
	{
		delete[] pData_;
		pData_ = nullptr;
	}
}

void MatrixU::swap(MatrixU& lhs, MatrixU& rhs)
{
	int* t = lhs.pData_;
	lhs.pData_ = rhs.pData_;
	rhs.pData_ = t;
}

MatrixU& MatrixU::operator=(const MatrixU& rhs)
{
	MatrixU::swap(*this, MatrixU(rhs));
	nRow_ = rhs.nRow_;
	nCol_ = rhs.nCol_;
	return *this;
}


bool MatrixU::operator==(const MatrixU& rhs) const
{
	bool b = true;
	for (int j(0); j < nRow_; j++)
	{
		for (int i{ 0 }; i < nCol_; i++)
		{
			if (pData_[nCol_ * j + i] != rhs.pData_[nCol_ * j + i])
			{
				b = false;
			}
		}
	}
	return b;
}

bool MatrixU::operator!=(const MatrixU& rhs) const
{
	return !(operator==(rhs));
}

int& MatrixU::At(const ptrdiff_t iRow, const ptrdiff_t iCol)
{
	if ((iRow < 0) || (iCol < 0) || (iRow >= nRow_) || (iCol >= nCol_)) { throw invalid_argument("Error2: Out of range"); }
	return pData_[nCol_ * iRow + iCol];
}

const int& MatrixU::At(const ptrdiff_t iRow, const ptrdiff_t iCol) const
{
	if ((iRow < 0) || (iCol < 0) || (iRow >= nRow_) || (iCol >= nCol_)) { throw invalid_argument("Error3: Out of range"); }
	return pData_[nCol_ * iRow + iCol];
}


ostream& MatrixU::writeTo(std::ostream& ostrm) const
{
	if (pData_ != nullptr)
	{
		for (int j(0); j < nRow_; j++)
		{
			for (int i{ 0 }; i < nCol_; i++)
			{
				ostrm << pData_[nCol_ * j + i] << ' ';
			}
			ostrm << endl;
		}
	}
	else {
		ostrm << "Array was deleting";
	}
	return ostrm;
}

ostream& operator<<(std::ostream& ostrm, const MatrixU& rhs)
{
	return rhs.writeTo(ostrm);
}


int MatrixU::Row_() const
{
	return nRow_;
}

int MatrixU::Col_() const
{
	return nCol_;
}

MatrixU& MatrixU::resize(const ptrdiff_t r, const ptrdiff_t c)
{
	if ((r <= 0) || (c <= 0)) {
		throw length_error("Error: Length eror - Size can't be less or equals 0");
	}
	if ((nRow_ != r) && (nCol_ != c))
	{
		int elementsRow = nRow_;
		if (nRow_ > r)
		{
			elementsRow = r;
		}
		int elementsCol = nCol_;
		if (nCol_ > c)
		{
			elementsCol = c;
		}

		int* pData_new = new int[r * c]{ int() };

		for (int j(0); j < elementsRow; j++)
		{
			for (int i{ 0 }; i < elementsCol; i++)
			{
				pData_new[c * j + i] = pData_[nCol_ * j + i];
			}
		}
		delete[] pData_;
		pData_ = pData_new;
		nRow_ = r;
		nCol_ = c;
	}
	return *this;
}