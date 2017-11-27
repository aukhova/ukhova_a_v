#ifndef STACKL_H
#define STACKL_H

#include <iosfwd>

class StackL
{
public:
	StackL() = default;
	~StackL();
	bool isEmpty()const;
	void Push(const int& value);
	void Pop();
	int& Top();
	const int& Top()const;
	void Clear();
	StackL (const StackL& rhs);
	StackL& operator=(const StackL& rhs);
	std::ostream& writeTo(std::ostream& ostrm) const;

private:
	struct Node
	{
		Node(Node* pNext, const int& value);
		~Node() = default;
		Node* pNext_{ nullptr };
		int pData_{ int() };
	};
	Node* pHead_{ nullptr };
};

std::ostream& operator<<(std::ostream& ostrm, const StackL& rhs);

#endif 