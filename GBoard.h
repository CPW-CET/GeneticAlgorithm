//Board.h
//Title: Generic Board Class
//Platform: C++ Win32 Console Visual Studio 2010
#pragma once
#include <string>
#include <iomanip>
#include <sstream>
#include <iostream>
using namespace std;
#include "Random.h"
#include "Evaluator.h"


class CBoard
{
protected:
	int m_rows;
	int m_columns;
	string* m_board;
public:
	CBoard(int rows, int columns);
	CBoard(void);
	~CBoard(void);
	void Value(int row, int column, string value);
	string  Value(int row, int column);
	int Rows();
	int Columns();
	int GetRows();
	int GetColumns();
	string ToString();
	void setNewBoard();
	void newPlacement(int X, int Y, bool firstMove, bool pickUp, int &Fitness);
	string& operator[](const int& index);
	void Verification(int Rows, int Columns);
};

