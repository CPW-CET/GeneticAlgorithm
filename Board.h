#include <random>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#pragma once
#include "TileType.h"

class Board
{
private:
	bool mBoard[10][10];
public:
	Board();
	~Board();
	TileType::tile getValue( int x, int y );
	void setValue( int x, int y, bool b );
	std::string ToString(void);
};