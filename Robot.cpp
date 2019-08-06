#include "Robot.h"

Robot::Robot()
{
	random_device mR;
	for( int i = 0; i < 243; i++ )		//Loop to make the 243 genes for the robot
	{
		mDNA.push_back((mR()%7)+'0');	//Picks a random value from 0-6 and pushes it back into the DNA strand
	}
}

Robot::Robot(string DNA)
{
	mDNA = DNA;
}

Robot::Robot(Phenotype &P) : Phenotype(P)
{

}

Robot::~Robot()
{

}

char Robot::getAction(int DNA_Index)
{
	char move_return;
	if (!(DNA_Index < 0 || DNA_Index >= 243 )) //Error checking to see if the asked DNA Index is outside our bounds
	{
		move_return = mDNA[DNA_Index]; //Takes the gene at the Index and puts it into move_return
	}
	else
	{
		move_return = 'X'; //If the asked DNA_Index is outside the Bounds, return X
	}
	return move_return; //Returns the gene and the DNA Index or X
}

void Robot::mutate()
{
	random_device mR;
	int x = 4;
	for (int i = 0; i < x; i++)		//Takes 4 genes to mutate
	{
		mDNA[mR()%243] = mR()%7+'0';	//At a random place in the DNA sequence changes the gene to something else
	}
}

void Robot::Initialize(void)
{
	random_device mR;
	int x = mR()%5 + 2;
	for (int i = 0; i < x; i++)
	{
		mDNA.at(mR()%243) = mR()%7;
	}
}
