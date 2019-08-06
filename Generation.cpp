//Generation.cpp
#include "Generation.h"

Generation::Generation(void)	:	mGenerationNumber(0), mMaxPopulation(200)
{
}


Generation::Generation(int maxPopulation)	:	mGenerationNumber(0), mMaxPopulation(maxPopulation)
{
}

Generation::Generation( list<Phenotype*> pPopulation )
{
	mpopulation = pPopulation;
}

Generation::~Generation(void)
{
}

void Generation::naturalSelection()
{

}

void Generation::populate()
{

}

void Generation::repopulate()
{

}

list<Phenotype*>* Generation::getPopulation()
{

	return &mpopulation;
}
