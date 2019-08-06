//Point.cpp
#include "Point.h"

CPoint::CPoint(double x, double y)
: m_xValue(x), m_yValue(y)
{
}

CPoint::CPoint(CPoint& rhs)
{
	m_xValue = rhs.m_xValue;
	m_yValue = rhs.m_yValue;
}

CPoint::~CPoint()
{
}

string CPoint::ToString()
{
	stringstream result;
	result << "(" << m_xValue;
	result << ", " << m_yValue;
	result << ")";
	return result.str();
}

double& CPoint::X(void)
{
	return m_xValue;
}

double& CPoint::Y(void)
{
	return m_yValue;
}

double CPoint::getDistance(CPoint point)
{
	return sqrt(pow(m_xValue-point.m_xValue,2)+
		        pow(m_yValue-point.m_yValue,2));
}

void CPoint::setXY(double x, double y)
{
	m_xValue = x;
	m_yValue = y;
}

double CPoint::getDirection(CPoint point)
{
	double direction = atan2(point.m_xValue-m_xValue,
		point.m_yValue-m_yValue)*RadiansToDegrees;
	if (direction < 0)
	{
		direction += 360.00;
	}
	return direction;
}

void CPoint::operator=(CPoint& rhs)
{
	m_xValue = rhs.m_xValue;
	m_yValue = rhs.m_yValue;
}

bool CPoint::operator==(CPoint& rhs)
{
	return (m_xValue == rhs.m_xValue &&
		    m_yValue == rhs.m_yValue);

}

bool CPoint::operator!=(CPoint& rhs)
{
	return(m_xValue != rhs.m_xValue ||
		   m_yValue != rhs.m_yValue);
}

CPoint CPoint::operator+(CPoint& rhs)
{
	return CPoint(m_xValue+rhs.m_xValue, m_yValue+rhs.m_yValue);
}

CPoint CPoint::operator-(CPoint& rhs)
{
	return CPoint(m_xValue-rhs.m_xValue, m_yValue-rhs.m_yValue);
}

CPoint& CPoint::operator+=(CPoint& rhs)
{
	m_xValue += rhs.m_xValue;
	m_yValue += rhs.m_yValue;
	return *this;
}

CPoint& CPoint::operator-=(CPoint& rhs)
{
	m_xValue -= rhs.m_xValue;
	m_yValue -= rhs.m_yValue;
	return *this;
}
