#include "priorityqueuel.h"
#include <iostream>
#include <stdexcept>

using namespace std;

PriorityQueueL::Node::Node(Node* pNext, const int& x)
	:pNext_(pNext)
	,pData_(x)
{
}

PriorityQueueL::PriorityQueueL(const PriorityQueueL& rhs)
{
	if (!rhs.isEmpty())
	{
		Node* t = rhs.pHead_;
		while (t != nullptr)
		{
			Push(t->pData_);
			t = t->pNext_;
		}
	}
}

bool PriorityQueueL::isEmpty() const
{
	return (nullptr == pHead_);
}

void PriorityQueueL::Push(const int& x)
{	
	if (isEmpty()) 
	{
		pTail_ = new Node(nullptr, x);
		 pHead_= pTail_;
	}
	
	else
	{
		pTail_->pNext_ = new Node(nullptr, x);
		pTail_ = pTail_->pNext_;
	}
}

//void PriorityQueueL::PushPr(const int& x)
//{
//	if (isEmpty())
//	{
//		pTail_ = new Node(nullptr, x);
//		pHead_ = pTail_;
//	}
//
//	else
//	{
//		if (x > pTail_->pData_)
//		{
//			if (x > pHead_->pData_)
//			{
//				Node* newHead = new Node(pHead_, x);
//				pHead_ = newHead;
//			}
//			else
//			{
//				Node* t = pHead_;
//				while ((t->pNext_)->pData_ > x)
//				{
//					t = t->pNext_;
//				}
//				/*Node* vsp = t->pNext_;*/
//				t->pNext_ = new Node(t->pNext_, x);
//			}
//		}
//		else
//		{
//			pTail_->pNext_ = new Node(nullptr, x);
//			pTail_ = pTail_->pNext_;
//		}
//		
//	}
//}

void PriorityQueueL::PushPr(const int& x)
{
	if ((isEmpty())||(x > pHead_->pData_))
	{
		pHead_ = new Node(pHead_, x);
		if (pTail_ == nullptr)
		{
			pTail_ = pHead_;
		}
		return;
	}

	if (x <pTail_->pData_)
	{
		pTail_->pNext_ = new Node(nullptr, x);
		pTail_ = pTail_->pNext_;
		return;
	}
			Node* t = pHead_;
			while ((t->pNext_)->pData_ > x)
			{
				t = t->pNext_;
			}
			t->pNext_ = new Node(t->pNext_, x);
				

}

void PriorityQueueL::Pop()
{
		if (isEmpty())
		{
			throw std::invalid_argument("Error: Stack is Empty");
		}
		else
		{
			Node* pDel(pHead_);
			pHead_ = pHead_->pNext_;
			delete pDel;
		}
}

int& PriorityQueueL::Top()
{
	if (isEmpty())
	{
		throw std:: invalid_argument("Error: Stack is Empty");
	}
	return pHead_->pData_;
}

const int& PriorityQueueL::Top() const
{
	if (isEmpty())
	{
		throw std::invalid_argument("Error: Stack is Empty");
	}
	return pHead_->pData_;
}

std::ostream& PriorityQueueL::writeTo(std::ostream& ostrm) const
{
	if (!isEmpty())
	{
		Node* t = pHead_;
		while (t != nullptr)
		{
			ostrm << t->pData_ << ' ';
			t = t->pNext_;
		}
	}
	else ostrm << "Stack is empty" << std::endl;
	return ostrm;
}

std::ostream& operator<<(std::ostream& ostrm, const PriorityQueueL& rhs)
{
	return rhs.writeTo(ostrm);
}

PriorityQueueL::~PriorityQueueL()
{
	while (!isEmpty())
	{
		Pop();
	}
}

PriorityQueueL& PriorityQueueL::operator=(const PriorityQueueL& rhs)
{
	Node* pCopyTo = pHead_;
	Node* pCopyFrom = rhs.pHead_;
	while ((pCopyTo->pNext_ != nullptr) && (pCopyFrom->pNext_ != nullptr))
	{
		pCopyTo->pData_ = pCopyFrom->pData_;
		pCopyTo = pCopyTo->pNext_;
		pCopyFrom = pCopyFrom->pNext_;
	}
	if ((pCopyTo->pNext_ == nullptr) && (pCopyFrom->pNext_ != nullptr))
	{
		pCopyTo->pData_ = pCopyFrom->pData_;
		pCopyFrom = pCopyFrom->pNext_;
		while (pCopyFrom != nullptr)
		{
			pCopyTo->pNext_ = new Node(nullptr, pCopyFrom->pData_);
			pCopyTo = pCopyTo->pNext_;
			pCopyFrom = pCopyFrom->pNext_;
		}
	}
	else
	{
		if ((pCopyFrom->pNext_ == nullptr) && (pCopyTo->pNext_ != nullptr))
		{
			pCopyTo->pData_ = pCopyFrom->pData_;
			Node* pContinue(pCopyTo->pNext_);
			pCopyTo->pNext_ = nullptr;
			Node* pDelete;
			while (pContinue != nullptr)
			{
				pDelete = pContinue;
				pContinue = pDelete->pNext_;
				delete pDelete;
			}
		}
	}
	return *this;
}