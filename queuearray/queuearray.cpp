#include "queuearray.h"
#include<iostream>
#include<sstream>
#include<cassert>

using namespace std;

QueueArray::QueueArray()
	:size_(defaultSize)
	, capacity_(0)
	, pHead_(0)
	, pTail_(0)
{
	pData_ = new int[size_] { int() };
}

QueueArray QueueArray::resize()
{
	QueueArray temp(*this);  //увеличиваем размер массива 
	if (!(pData_ == nullptr))
	{
		delete[] pData_;
		pData_ = nullptr;
	}
	size_ *= 2;
	pData_ = new int[size_] { int() };
	for (int i = temp.pHead_; i <= temp.pTail_; ++i)
		pData_[i] = temp.pData_[i];
	return(*this);
}

bool QueueArray::isEmpty()const
{
	return(0 == capacity_);
}

void QueueArray::Push(const int& value)
{
	if (pTail_ + 2 > size_)
	{
		if (pTail_ > capacity_ * 2)
			(*this).InStart();
		else
			(*this).resize();
	}
	pData_[pTail_ + 1] = value;   //прибавить элемент в конец массива
	capacity_++;
	pTail_++;
}

void QueueArray::Pop()
{
	if (isEmpty())
	{
		throw std::invalid_argument("Error: Stack is Empty");
	}
	else
	{
		pHead_++;
		capacity_--;
	}
}

int& QueueArray::Top()
{
	if (isEmpty())
	{
		throw invalid_argument("Error: Stack is Empty");
	}
	return pData_[pHead_];
}

const int& QueueArray::Top() const
{
	if (isEmpty())
	{
		throw invalid_argument("Error: Stack is Empty");
	}
	return pData_[pHead_];
}

ostream& QueueArray::writeTo(std::ostream& ostrm) const
{
	if (!(pData_ == nullptr))
	{
		if (capacity_ >= 1)
		{
			ostrm << scob1 << ' ';
			for (int i = pHead_; i < pTail_; i++)
				ostrm << pData_[i] << ", ";
			ostrm << pData_[pTail_] << ' ' << scob2;
		}
		else ostrm << "Array is empty";
	}
	else
		ostrm << "Array was deleting";
	return ostrm;
}

ostream& operator<<(std::ostream& ostrm, const QueueArray& rhs)
{
	return rhs.writeTo(ostrm);
}

int& QueueArray::operator[](const ptrdiff_t i)
{
	if ((i <= pTail_) && (i >= pHead_))
		return pData_[i];
	else throw invalid_argument("Error: Index can't be (i>pTail_ + 1) && (i <pHead_)");
}

const int& QueueArray:: operator[](const ptrdiff_t i) const
{
	if ((i <= pTail_) && (i >= pHead_))
		return pData_[i];
	else throw invalid_argument("Error: Index can't be (i>pTail_) && (i <pHead_)");
}

QueueArray::~QueueArray()
{
	if (pData_ != nullptr)
	{
		delete[] pData_;
		pData_ = nullptr;
	}
}

QueueArray::QueueArray(const QueueArray& rhs)
	:size_(rhs.size_)
	, capacity_(rhs.capacity_)
	, pHead_(rhs.pHead_)
	, pTail_(rhs.pTail_)
{
	pData_ = new int[rhs.size_]{ int() };
	for (int i = pHead_; i <= rhs.pTail_; i++)
		pData_[i] = rhs.pData_[i];
}

QueueArray QueueArray::InStart()
{
	QueueArray temp(*this);  //увеличиваем размер массива 
	if (!(pData_ == nullptr))
	{
		delete[] pData_;
		pData_ = nullptr;
	}
	pData_ = new int[size_] { int() };
	for (int i = 0; i <capacity_; ++i)
		pData_[i] = temp.pData_[i + pHead_];
	return(*this);
}