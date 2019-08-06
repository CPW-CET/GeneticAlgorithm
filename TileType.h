#pragma once
#include <string>
using namespace std;
const bool verbose = false;
const bool verbose2 = false;
const string tileOut[3] = { "wall", "can", "blank" };
const string moveOut[7] = { "North", "South", "East", "West", "Stay-Put", "Pick-Up", "Random" };
class TileType{
public:
	enum tile {wall, can, blank};
	enum move {moveNorth, moveSouth, moveEast, moveWest, stayPut, pickup, random};

};