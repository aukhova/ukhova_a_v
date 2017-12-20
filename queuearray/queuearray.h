#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H
#include <iosfwd>

class QueueArray
{
public:
	QueueArray();
	QueueArray(const QueueArray& rhs);
	~QueueArray();
	bool isEmpty()const;
	void Push(const int& value);
	void Pop();
	int& Top();
	const int& Top()const;
	QueueArray& operator=(const QueueArray& rhs);
	std::ostream& writeTo(std::ostream& ostrm) const;

private:
	QueueArray resize();
	QueueArray InStart();
	int& operator[](const ptrdiff_t i);
	const int& operator[](const ptrdiff_t i) const;
	void swap(QueueArray& lhs, QueueArray& rhs);
	static const int defaultSize = 5;
	ptrdiff_t pHead_{ 0 };
	ptrdiff_t pTail_{ 0 };
	ptrdiff_t capacity_{ 0 };
	ptrdiff_t size_{ 0 };
	int* pData_{ nullptr };
	static const char scob1{ '{' };
	static const char scob2{ '}' };
	static const char separator{ ',' };
};
std::ostream& operator<<(std::ostream& ostrm, const QueueArray& rhs);

#endif 