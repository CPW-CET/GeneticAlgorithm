#pragma once
#include <string>
#include <list>
#include <stack>
#include "Phenotype.h"

using namespace std;

class Generation
{
protected:
	list<Phenotype*> mpopulation; // Container to hold all of the Phenotypes in a generation
	int mGenerationNumber;
	int mMaxPopulation;
public:
	Generation();
	Generation(int maxPopulation);
	Generation(list<Phenotype*> pPpopulation );
	~Generation();

	// Sorts population based on fitness level
	// Removes creatures that are unfit
	virtual void naturalSelection();

	// Creates maxPopulation Phenotypes with random DNA
	virtual void populate();

	// Adds newly created Phenotypes to the generation
	// stops when #of phenotypes in population = maxPopulation
	virtual void repopulate();

	// returns a reference of the population
	virtual list<Phenotype*>* getPopulation();
};