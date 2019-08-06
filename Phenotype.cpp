#include "Phenotype.h"


Phenotype::Phenotype()
{
	mFitness = 0;
}

Phenotype::Phenotype(string DNA)
{
	mDNA = DNA;
	mFitness = 0;
}

Phenotype::~Phenotype()
{
}

string& Phenotype::getDNA()
{
	return mDNA;
}

string Phenotype::reproduce( int DNA_Start, int DNA_END )
{
	string DNA_Return;
	// makes sure that the starting index is not negative
	if( DNA_Start < 0 )
	{
		DNA_Return = "DNA starting index is negative  ";
	}
	// makes sure that the end index is not out of bounds
	else if( DNA_END > 243)
	{
		DNA_Return = "DNA end index is too high  ";
	}
	// makes sure that the end index isnt less than the start index
	else if( DNA_Start > DNA_END )
	{
		DNA_Return = "DNA indexes overlap";
	}
	else
	{
		//mutate();
		for( int i = DNA_Start; i <= DNA_END; i++ )
		{
			DNA_Return += mDNA[i];
		}
	}
	return DNA_Return;
}

int& Phenotype::getFitness()
{
	return mFitness;
}

bool Phenotype::operator<(Phenotype P)
{
	bool temp = false;
	if( mFitness < P.getFitness() )
	{
		temp = true;
	}
	return temp;
}

bool Phenotype::operator>(Phenotype P)
{
	bool temp = false;
	if( mFitness > P.getFitness() )
	{
		temp = true;
	}
	return temp;
}

bool Phenotype::operator<=(Phenotype P)
{
	bool temp = false;
	if( mFitness <= P.getFitness() )
	{
		temp = true;
	}
	return temp;
}

bool Phenotype::operator>=(Phenotype P)
{
	bool temp = false;
	if( mFitness >= P.getFitness() )
	{
		temp = true;
	}
	return temp;
}

bool Phenotype::operator!=(Phenotype P)
{
	bool temp = false;
	if( mFitness != P.getFitness() )
	{
		temp = true;
	}
	return temp;
}

bool Phenotype::operator==(Phenotype P)
{
	bool temp = false;
	if( mDNA == P.getDNA() )
	{
		temp = true;
	}
	return temp;
}

char Phenotype::getAction( int DNA_Index )
{
	return 'a';
}

void Phenotype::mutate()
{
	random_device mR;
	int x = 5;
	int index = 0;
	for (int i = 0; i < x; i++)		//Takes 3 genes to mutate
	{
		index = (mR()%243);
		mDNA[index] = (mR()%7)+'0';	//At a random place in the DNA sequence changes the gene to something else
	}
}