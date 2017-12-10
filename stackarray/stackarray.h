#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stddef.h>
#include <iosfwd>

using namespace std; 

class StackArray
{
public:
	StackArray();
	StackArray(const StackArray& rhs);
	~StackArray();
	bool isEmpty()const;
	void Push(const int& value);
	void Pop();
	int& Top();
	const int& Top()const;
	void Clear();
	StackArray& operator=(const StackArray& rhs);
	ostream& writeTo(std::ostream& ostrm) const;
	
private:
	StackArray resize();
	StackArray resize(const ptrdiff_t i);
	int& operator[](const ptrdiff_t i);
	const int& operator[](const ptrdiff_t i) const;
	void swap(StackArray& lhs, StackArray& rhs);
	static const int defaultSize = 5;
	ptrdiff_t capacity_{ 0 };
	ptrdiff_t size_{ 0 };
	int* pData_{ nullptr };
	static const char scob1{ '{' };
	static const char scob2{ '}' };
	static const char separator{ ',' };
};
ostream& operator<<(std::ostream& ostrm, const StackArray& rhs);
#endif 
