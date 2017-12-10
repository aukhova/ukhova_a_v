#include "stackarray.h"
#include<iostream>
#include<sstream>
#include<cassert>

using namespace std;

StackArray::StackArray()
	:size_(defaultSize)
	, capacity_(0)
{
	pData_ = new int[size_] { int() };
}

StackArray StackArray::resize()
{
	StackArray temp(*this);  //увеличиваем размер массива 
	if (!(pData_ == nullptr))
	{
		delete[] pData_;
		pData_ = nullptr;
	}
	size_ *= 2;
	pData_ = new int[size_] { int() };
	for (int i = 0; i<temp.capacity_; ++i)
		pData_[i] = temp.pData_[i];
	return(*this);
}

//StackArray StackArray::resize(const ptrdiff_t s)
//{
//	StackArray temp(*this);  //увеличиваем размер массива 
//	if (!(pData_ == nullptr))
//	{
//		delete[] pData_;
//		pData_ = nullptr;
//	}
//	size_ = s;
//	pData_ = new int[size_] { int() };
//	for (int i = 0; i<temp.capacity_; ++i)
//		pData_[i] = temp.pData_[i];
//	return(*this);
//}

void StackArray::swap(StackArray& lhs, StackArray& rhs)
{
	int* t_ = lhs.pData_;
	lhs.pData_ = rhs.pData_;
	rhs.pData_ = t_;
}

StackArray& StackArray::operator=(const StackArray& rhs)
{
	swap(*this, StackArray(rhs));
	capacity_ = rhs.capacity_;
	return *this;
}

bool StackArray:: isEmpty()const
{
	return(0 == capacity_);
}

void StackArray::Push(const int& value)
{
	if (capacity_ + 1 > size_)
	{
		(*this).resize();
	}
	pData_[capacity_] = value;   //прибавить элемент в конец массива
	capacity_++;
}

void StackArray::Pop()
{
	if (isEmpty())
	{
		throw invalid_argument("Error: Stack is Empty");
	}
	else
	{
		capacity_--;
	}
}

int& StackArray::operator[](const ptrdiff_t i)
{
	if (i<capacity_)
		return pData_[i];
	else throw invalid_argument("Error: Index can't be >= capacity_");
}

const int& StackArray::operator[](const ptrdiff_t i) const
{
	if (i<capacity_)
		return pData_[i];
	else throw invalid_argument("Error: Index can't be >= capacity_");
}

int& StackArray::Top()
{
	if (isEmpty())
	{
		throw invalid_argument("Error: Stack is Empty");
	}
	return pData_[capacity_-1];
}

const int& StackArray::Top() const
{
	if (isEmpty())
	{
		throw invalid_argument("Error: Stack is Empty");
	}
	return pData_[capacity_ - 1];
}

void StackArray::Clear()
{
	capacity_ = 0;
}

StackArray::StackArray(const StackArray& rhs)
	:size_(rhs.size_)
	, capacity_(rhs.capacity_)
{
	pData_ = new int[rhs.size_]{ int() };
	for (int i(0); i < rhs.size_; i++)
		pData_[i] = rhs.pData_[i];
}

StackArray::~StackArray()
{
	if (!(pData_ == nullptr))
	{
		delete[] pData_;
		pData_ = nullptr;
	}
}

ostream& StackArray::writeTo(std::ostream& ostrm) const
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

ostream& operator<<(std::ostream& ostrm, const StackArray& rhs)
{
	return rhs.writeTo(ostrm);
}