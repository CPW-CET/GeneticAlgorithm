#include "GA.h"
#include <iostream>

GA::GA(Evaluator& E, Generation& G)
{
	mE = &E;
	mG = &G;
}

GA::~GA()
{

}

void GA::start(int numberOfGenerations)
{
	stringstream result;
	string mFileName = "RoboDNA.txt";
	for( int i = 0; i < numberOfGenerations; i++ )
	{
		list<Phenotype*>::iterator it;
		mE->evaluate(mG->getPopulation());	//Evaluates the population
		mG->naturalSelection();				//Takes the population after being evaluted and destroys the last half of robots
		mG->repopulate();					//Repopulates until the population is back to the initial number

		it = mG->getPopulation()->begin();
		result << (*it)->getFitness() << endl;
		if(i == numberOfGenerations - 1)
		{
			Reporter::Save(mFileName,(*it)->getDNA());
		}
		int q = 0;
		if(verbose)
		{
		while( !(it == mG->getPopulation()->end() ) )
		{
			//cout << mG->getPopulation().size() << " : ";
			cout << (*it)->getFitness() << endl;
			it++;
			q++;
			if(q == 50)
			{
				cout << "Generation: " << i+1;
				break;
			}

		}
		}

		cout << endl;
	}


	Reporter::reportGeneration(result.str());
}

void GA::compare()
{
	
	string bDNA="";
	list<Phenotype*>::iterator it;
	int bestFit=0;
	while(((*it)->getFitness() > bestFit)) //Gets the best fit robot and associates it with the robot's DNA.
	{
		bDNA=(*it)->getDNA();
		bestFit=(*it)->getFitness();
	}

}
