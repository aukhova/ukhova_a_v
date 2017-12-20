#ifndef PRIORITYQUEUEL_H
#define PRIORITYQUEUEL_H
#include <iosfwd>

class PriorityQueueL
{
public:
	PriorityQueueL() = default;
	~PriorityQueueL();
	PriorityQueueL(const PriorityQueueL& rhs);
	PriorityQueueL& operator=(const PriorityQueueL& rhs);
	void Push(const int& x);
	void Pop();
	void PushPr(const int& x);
	int& Top();
	const int& Top() const;
	bool isEmpty() const;
	std:: ostream& writeTo(std::ostream& ostrm) const;

private:
	struct Node
	{
		Node(Node* pNext, const int& x);
		~Node() = default;
		Node* pNext_{ nullptr };
		int pData_{ int(0) };
	};
	Node* pHead_{ nullptr };
	Node* pTail_{ nullptr };
};

std::ostream& operator<<(std::ostream& ostrm, const PriorityQueueL& rhs);

#endif 