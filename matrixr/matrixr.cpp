#include "matrixR.h"
#include<iostream>
#include<sstream>
#include <stdexcept>

using namespace std;

MatrixR::MatrixR(): nRow_(defaultRow_), nCol_(defaultCol_)
{
	pRows_ = new int*[nRow_] {nullptr};
	pRows_[0] = new int[nCol_*nRow_]{ int(0) };
	for (int i(0); i < nRow_ - 1; i++)
	{
		pRows_[i + 1] = pRows_[i] + nCol_;
	}
}

MatrixR::MatrixR(const int row, const int col) : nRow_(row), nCol_(col)
{
	if ((row <= 0) || (col <= 0)) { throw invalid_argument("Error: Size can't be less or equals 0"); }
	pRows_ = new int*[nRow_] {nullptr};;
	pRows_[0] = new int[nCol_*nRow_]{ int(0) };
	for (int i(0); i < nRow_ - 1; i++)
	{
		pRows_[i + 1] = pRows_[i] + nCol_;
	}
}

MatrixR::MatrixR(const MatrixR& rhs) : nRow_(rhs.nRow_), nCol_(rhs.nCol_)
{
	pRows_ = new int*[nRow_] {nullptr};
	pRows_[0] = new int[nRow_ * nCol_]{ int(0) };
	for (int i(0); i < nRow_ - 1; i++)
	{
		pRows_[i + 1] = pRows_[i] + nCol_;
	}

	for (int j(0); j < nRow_; j++)
	{
		for (int i(0); i < nCol_; i++)
		{
			pRows_[j][i] = rhs.pRows_[j][i];
		}
	}
}

MatrixR::~MatrixR()
{
	if (pRows_ != nullptr)
	{
		delete[]  pRows_[0];
		delete[]  pRows_;
		pRows_ = nullptr;
	}
}

void MatrixR::swap(MatrixR& lhs, MatrixR& rhs)
{
	int** t = lhs.pRows_;
	lhs.pRows_ = rhs.pRows_;
	rhs.pRows_ = t;
}

MatrixR& MatrixR::operator=(const MatrixR& rhs)
{
	MatrixR::swap(*this, MatrixR(rhs));
	nRow_ = rhs.nRow_;
	nCol_ = rhs.nCol_;
	return *this;
}

bool MatrixR::operator==(const MatrixR& rhs) const
{
	bool result = true;
	for (int j(0); j < nRow_; j++)
	{
		for (int i(0); i < nCol_; i++)
		{
			if (pRows_[j][i] != rhs.pRows_[j][i])
			{
				result = false;
			}
		}
	}
	return result;
}


bool MatrixR::operator!=(const MatrixR& rhs) const
{
	return !(operator==(rhs));
}


int& MatrixR::At(const ptrdiff_t iRow, const ptrdiff_t iCol)
{
	if ((iRow < 0) || (iCol < 0) || (iRow >= nRow_) || (iCol >= nCol_)) { throw invalid_argument("Error2: Out of range"); }
	return pRows_[iRow][iCol];
}

const int& MatrixR::At(const ptrdiff_t iRow, const ptrdiff_t iCol) const
{
	if ((iRow < 0) || (iCol < 0) || (iRow >= nRow_) || (iCol >= nCol_)) { throw invalid_argument("Erro3: Out of range"); }
	return pRows_[iRow][iCol];
}

ostream& MatrixR::writeTo(std::ostream& ostrm) const
{
	if (pRows_ != nullptr)
	{
		for (int j(0); j < nRow_; j++)
		{
			for (int i(0); i < nCol_; i++)
			{
				ostrm << pRows_[j][i] << ' ';
			}
			ostrm << endl;
		}
	}
	else
	{
		ostrm << "Array was deleting or wasn't created";
	}
	return ostrm;
}

ostream& operator<<(std::ostream& ostrm, const MatrixR& rhs)
{
	return rhs.writeTo(ostrm);
}

int MatrixR::lenth() const
{
	return nCol_ * nRow_;
}

MatrixR& MatrixR::resize(const ptrdiff_t r, const ptrdiff_t c)
{
	if ((r < 0) || (c < 0)) {
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

		int** pRows_new = new int*[r] { nullptr };

		pRows_new[0] = new int[r * c]{ int(0) };
		for (int i(0); i < r - 1; i++)
		{
			pRows_new[i + 1] = pRows_new[i] + c;
		}


		for (int j(0); j < elementsRow; j++)
		{
			for (int i{ 0 }; i < elementsCol; i++)
			{
				pRows_new[j][i] = pRows_[j][i];
			}
		}
		delete[]  pRows_[0];
		delete[]  pRows_;
		pRows_ = pRows_new;
		nRow_ = r;
		nCol_ = c;
	}
	return *this;
}

MatrixR MatrixR::operator*(const MatrixR& rhs) const
{
	if (nCol_ != rhs.nRow_) { throw invalid_argument("Error: can't (*) these matrixes"); }
	MatrixR result(nRow_, rhs.nCol_);
	for (int jR(0); jR < nRow_; jR++)
	{
		for (int iC(0); iC < rhs.nCol_; iC++)
		{
			for (int umnojCol(0); umnojCol < nCol_; umnojCol++)
			{
				result.At(jR, iC) += pRows_[jR][umnojCol] * rhs.At(umnojCol, iC);
			}
		}
	}
	return result;
}