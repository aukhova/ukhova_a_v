#include "array.h"
#include<iostream>
#include<sstream>
#include<cassert>

using namespace std;

Array::Array()
	:size_(defaultSize)
	, capacity_(0)
{
	pData_ = new int[size_] { int() };
}

Array::Array(const int size)
	:size_(size)
	, capacity_(0)
{
	if (size <= 0) throw invalid_argument("Error: Size can't be less or equals 0");
	pData_ = new int[size] { int() };
}

Array::Array (const Array& rhs)
	:size_(rhs.size_)
	,capacity_(rhs.capacity_)
{
	pData_ = new int[rhs.size_]{ int() };
		for (int i(0); i < rhs.size_; i++)
			pData_[i] = rhs.pData_[i];
}

Array::~Array()
{
	if (!(pData_ == nullptr))
	{
		delete[] pData_;
		pData_ = nullptr;
	}
}

int& Array::operator[](const ptrdiff_t i)
{
	if (i<capacity_)
		return pData_[i];
	else throw invalid_argument("Error: Index can't be >= capacity_");
}

const int& Array:: operator[](const ptrdiff_t i) const
{
	if (i<capacity_)
	return pData_[i];
	else throw invalid_argument("Error: Index can't be >= capacity_");
}

int Array::size() const
{
	return size_;
}
int Array::lenth() const
{
	return capacity_;
}

void Array:: Add(const int x)
{
	if (capacity_+1> size_) 
	{      
		Array temp(*this);  //увеличиваем размер массива 
		if (!(pData_ == nullptr))
		{
			delete[] pData_;
			pData_ = nullptr;
		}
		size_ += 5;
		pData_ = new int[size_] { int() };
		for (int i = 0; i<temp.capacity_; ++i)
			pData_[i] = temp.pData_[i];
	}
	pData_[capacity_] = x;   //прибавить элемент в конец массива
	capacity_++;
}

void Array::Add(const int x, const int n)
{
	if ((n < 0) || (n > capacity_)) throw out_of_range("Error: You can not add an item because its index > capacity_ or index<0");
	if (capacity_ + 1 > size_)
	{
		Array temp(*this);  //увеличиваем размер массива 
		if (!(pData_ == nullptr))
		{
			delete[] pData_;
			pData_ = nullptr;
		}
		size_ += 5;
		pData_ = new int[size_] { int() };
		for (int i = 0; i<temp.capacity_; ++i)
			pData_[i] = temp.pData_[i];
	}
	for (int j(capacity_); j > n; j--)
	{
		pData_[j] = pData_[j - 1];
	}
	pData_[n] = x;   
	capacity_++;;
}

void Array::remove(const int i)
{
	if ((i < 0) || (i >= capacity_)) throw out_of_range("Error: Out of range in remove");
	for (int j(i); j < capacity_ - 1; j++)
	{
		pData_[j] = pData_[j + 1];
	}
	capacity_--;
}

ostream& Array::writeTo(std::ostream& ostrm) const
{
	if (!(pData_ == nullptr))
	{
		if (capacity_ >= 1)
		{
			ostrm << scob1 << ' ';
			for (int i(0); i < capacity_ - 1; i++)
				ostrm << pData_[i] << ", ";
			ostrm << pData_[capacity_ - 1] << ' ' << scob2;
		}
		else ostrm << "Array is empty";
	}
	else
		ostrm << "Array was deleting";
	return ostrm;
}

ostream& operator<<(std::ostream& ostrm, const Array& rhs)
{
	return rhs.writeTo(ostrm);
}

void Array::swap(Array& lhs, Array& rhs)
{
	int* t_ = lhs.pData_;
	lhs.pData_ = rhs.pData_;
	rhs.pData_ = t_;
}

Array& Array::operator=(const Array& rhs)
{
	swap(*this, Array(rhs));
	capacity_ = rhs.capacity_;
	return *this;
}