/*
*/
#pragma once
#include <sstream>
#include "Phenotype.h"

class Robot : public Phenotype
{
private:
	
public:

	Robot();
	Robot(string DNA);
	Robot(Phenotype& P);
	~Robot();

	// returns a character from the DNA sequence at the specified index
	// max index = 243
	// index = situation selected from the situation table
	// char = move to be made in specified situation
	// valid characters = 0, 1, 2, 3, 4, 5, 6
	char getAction(int DNA_Index);

	// randomly changes 1 character in DNA to a value from 0 - 6
	void mutate();
	void Initialize(void);
};