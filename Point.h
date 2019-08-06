//Point.h
#pragma once
#include <iostream>
#include <sstream>
using namespace std;
const double PI = acos(-1.0);
const double DegreesToRadians = PI/180.0;
const double RadiansToDegrees = 180.0/PI;

class CPoint  
{
protected:
	double m_yValue;
	double m_xValue;
public:
	CPoint(double x=0.0, double y=0.0);
	CPoint(CPoint& rhs);
	virtual ~CPoint();
	string ToString();
	double& X(void);
	double& Y(void);
	void setXY(double x, double y);
	double getDistance(CPoint point);
	double getDirection(CPoint point);
	void operator=(CPoint& rhs);
	bool operator==(CPoint& rhs);
	bool operator!=(CPoint& rhs);
	CPoint  operator+(CPoint& rhs);
	CPoint& operator+=(CPoint& rhs);
	CPoint  operator-(CPoint& rhs);
	CPoint& operator-=(CPoint& rhs);
};