#pragma once
#include <string>
#include <random>

using namespace std;


class Phenotype
{
protected:
	string mDNA;			
	signed int mFitness; 
public:
	// empty constructor initalizes the DNA to blank spaces
	Phenotype();
	// creates new Phenotype with mDNA = DNA
	Phenotype(string DNA);
	~Phenotype();
		
	// returns a character from the DNA sequence at the specified index
	virtual char getAction(int DNA_Index);
		
	// randomly changes gene/genes
	virtual void mutate();

	// returns DNA after specified index as a string
	string reproduce(int DNA_Start, int DNA_End);

	// acessor for the mFitness variable
	int& getFitness();
	string& getDNA();

	bool operator > (Phenotype P);
	bool operator < (Phenotype P);
	bool operator >= (Phenotype P);
	bool operator <= (Phenotype P);
	bool operator != (Phenotype P);
	bool operator == (Phenotype P);
};