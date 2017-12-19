#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>
#include <iosfwd>

using namespace std;


class Array
{
public:
	Array();
	Array(const int size);
	Array(const Array& rhs);
	~Array();
	Array& operator=(const Array& rhs);
	int& operator[](const ptrdiff_t i);
	const int& operator[](const ptrdiff_t i) const;
	ostream& writeTo(std::ostream& ostrm) const;
	int size() const;
	int lenth() const;
	void Add(const int x);
	void Add(const int x, const int i);
	void remove(const int i);
	void swap(Array& lhs, Array& rhs);
private:
	static const int defaultSize = 5;
	ptrdiff_t capacity_{ 0 };
	ptrdiff_t size_{ 0 };
	int* pData_{ nullptr };
	static const char scob1{ '{' };
	static const char scob2{ '}' };
	static const char separator{ ',' };
};
ostream& operator<<(std::ostream& ostrm, const Array& rhs);
#endif 