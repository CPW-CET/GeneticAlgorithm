#pragma once
#include "Generation.h"
#include <list>
#include <iterator>

using namespace std;

/*
*	Evaluator is specific to its Phenotype
*/
class Evaluator
{
public:
	Evaluator();
	~Evaluator();

	// judges the fitness of indivitual Phenotypes in the generation G
	// over a set number of repeated tests
	virtual void evaluate( list<Phenotype*>* G );
};