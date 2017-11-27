#include "stackL.h"
#include <stdexcept>
#include <iostream>


using namespace std;


StackL::Node::Node(Node* pNext, const int& value)
	:pNext_(pNext),
	pData_(value)
{

}

bool StackL::isEmpty()const
{
	return nullptr == pHead_;
}

void StackL::Push(const int& value)
{
	pHead_ = new Node(pHead_, value);
}

void StackL::Pop()
{
	if (isEmpty())
	{
		throw invalid_argument("Error: Stack is Empty");
	}
	else
	{
		Node* pDel(pHead_);
		pHead_ = pHead_->pNext_;
		delete pDel;
	}
}

int& StackL::Top()
{
	if (isEmpty()) 
	{
		throw invalid_argument("Error: Stack is Empty");
	}
	return pHead_->pData_;
}

const int& StackL::Top() const
{
	if (isEmpty())
	{
		throw invalid_argument("Error: Stack is Empty");
	}
	return pHead_->pData_;
}

StackL::~StackL()
{
	(*this).Clear();
}

StackL::StackL(const StackL& rhs)
{
	StackL turned;
	Node* pForget(rhs.pHead_);
	while (nullptr != (pForget))
	{
		turned.Push(pForget->pData_);
		pForget = pForget->pNext_;
	}
	while (!turned.isEmpty())
	{
		Push(turned.Top());
		turned.Pop();
	}
}

StackL& StackL::operator=(const StackL& rhs)
{
	StackL turned;
	Node* pForget(rhs.pHead_);
	while (nullptr != (pForget))
	{
		turned.Push(pForget->pData_);
		pForget = pForget->pNext_;
	}
	while (!turned.isEmpty())
	{
		Push(turned.Top());
		turned.Pop();
	}
	return *this;
}

void StackL::Clear()
{
	while (!isEmpty())
	{
		Pop();
	}
}

ostream& StackL::writeTo(std::ostream& ostrm) const
{
	StackL copyStack(*this);
	if (!isEmpty())
	{
		while (!copyStack.isEmpty())
		{
			ostrm << copyStack.Top() << endl;
			copyStack.Pop();
		}
	}
	else ostrm << "Stack is empty" << endl;
	return ostrm;
}

ostream& operator<<(std::ostream& ostrm, const StackL& rhs)
{
	return rhs.writeTo(ostrm);
}