//Iterator.cpp
#include "Iterator.h"

CIterator::CIterator(void)
: m_start(0),
m_index(0),
m_end(0)
{
}

CIterator::CIterator(int start, int end)
{
	m_start = start;
	m_index = start;
	m_end = end;
}

CIterator::~CIterator(void)
{
}

int CIterator::begin(void)
{
	return m_start;
}

int CIterator::end(void)
{
	return m_end;
}

void CIterator::operator++(void) //prefix operator
{
	if (m_index < m_end)
	{
		m_index++;
	}
}

void CIterator::operator++(int iterator) //postfix operator
{
	if (m_index < m_end)
	{
		m_index++;
	}
}

int CIterator::current(void)
{
	return m_index;
}

