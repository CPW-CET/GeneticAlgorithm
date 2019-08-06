//Iterator.h
//Title: Iterator Class
//Platform: C++ Win32 Console Visual Studio 2010
#pragma once

class CIterator
{
private:
	int m_index;
	int m_start;
	int m_end;
public:
	CIterator(void);
	CIterator(int start, int end);
	~CIterator(void);
	int begin(void);
	int end(void);
	void operator++(void);
	void operator++(int iterator);
	int current(void);
};
