#pragma once
#include "Generation.h"
#include "Robot.h"
#include "TileType.h"
#include <random>
#include <string>
#include <cmath>
const int Terminator = 200; 

using namespace std;

class RoboGeneration : public Generation
{
protected:
	int mNumberOfEvaluations;
public:

	RoboGeneration();
	RoboGeneration(int maxPopulation);
	RoboGeneration( list<Phenotype*> pPopulation);
	~RoboGeneration();

	// Sorts population based on fitness level
	// Removes creatures that are unfit
	void naturalSelection();

	// Creates a new population with random DNA
	void populate();

	// Adds newly created Phenotypes to the generation
	 
	void repopulate();

	// returns a reference of the population
	list<Phenotype*>* getPopulation();

private:

	// creates a new Robot based on a combination of genetic material
	// calculations for how much genetic material from each is included
	void mate( Phenotype a, Phenotype b );
};