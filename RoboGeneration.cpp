//RoboGeneration.cpp
#include "RoboGeneration.h"
#include <iostream>

RoboGeneration::RoboGeneration(void) : Generation()
{
}

RoboGeneration::RoboGeneration(int maxPopulation) : Generation(maxPopulation)
{
	populate();
}

RoboGeneration::RoboGeneration( list<Phenotype*> pPopulation) : Generation( pPopulation )
{

}

RoboGeneration::~RoboGeneration()
{
}

void RoboGeneration::populate(void) // first time
{
	for (int i = 0; i < mMaxPopulation; i++) //Making the initial population of robots
	{
		mpopulation.push_back(new Robot());
	}
}

void RoboGeneration::repopulate(void) // every other time
{

	random_device mR;
	list<Phenotype*>::iterator it;
	// calculate probability of mating
	list<Phenotype> Above75; //List for robots that have a fitness greater than 75%
	list<Phenotype> Above50; //List for robots that have a fitness greater than 50%
	list<Phenotype> Above25; //List for robots that have a fitness greater than 25%
	list<Phenotype> Rest;    //List for the other robots
	double max, min, range, quarter1, half, quarter3;
	max = mpopulation.front()->getFitness() + 1000; //Taking the first robot's fitness to find the max
	min = mpopulation.back()->getFitness() + 1000;  //Taking the last robot's fitness to find the min

	range = max - min;   
	if(range == 0)
	{
		range = 1;
	}                                    // 0%       10%       25%       50%       100%
	quarter1 = (range / 4) + min;        // |---------|---------|---------|---------|
	half = (range / 2 ) + min;			 // Min    Quarter1    Half   Quarter3     Max
	quarter3 = ( 3 * range / 4 ) + min;	 
	it = mpopulation.begin();
	if(verbose)
	{
	cout << "Range: " << range;
	cout << "\nMin: " << min << endl;
	cout << "Max: " << max << endl;
	}

	while( it != mpopulation.end() )
	{
	    if(((*it)->getFitness() + 1000) >= quarter3) //If the robot's fitness is greater than Quarter 3, put it in the Above75 list
		{
			Above75.push_back(*(*it));
		}
		else if(((*(*it)).getFitness() + 1000) >= half) //If the robot's fitness is greater than the Half but less than Quarter 3, put it in the Above50 list
		{
			Above50.push_back(*(*it));
		}
		else if(((*(*it)).getFitness() + 1000) >= quarter1) //If the robot's fitness is greater than the Quarter 1 but less than the Half, put it in the Above25 list
		{
			Above25.push_back(*(*it));
		}
		else //If the robot's fitness is greater than the Min but less than the Quarter 1, put it in the Rest list
		{
			Rest.push_back(*(*it));
		}

		it++;


	}


	for (int i = mpopulation.size(); i < mMaxPopulation; i= i+2) //Repopulating the population to get the same amount of robots as the initial
	{
		Phenotype robot[2];
		int probability;

		stack<Phenotype> roboStack;

		do
		{
			for( int j = 0; j < 2; j++) //Finds 2 probabilites for mating 2 robots
			{
				probability = abs((double)(mR()%100)); //Random Probability between 0 and 100%
				if( probability >=60 ) //If the probability is greater than 50%, take from the Above75 list
				{
					if( Above75.size() != 0 )
					{
						for( int i = (abs((double)(mR()%(Above75.size())))); i >= 0; i-- ) //!!!!!!!!!!Not sure what this does exactly!!!!!!!!!!
						{																  //!!!!!!!!!!Not sure what this does exactly!!!!!!!!!!
							roboStack.push(Above75.front());							  //!!!!!!!!!!Not sure what this does exactly!!!!!!!!!!
							Above75.pop_front();										  //!!!!!!!!!!Not sure what this does exactly!!!!!!!!!!
						}																  //!!!!!!!!!!Not sure what this does exactly!!!!!!!!!!
						robot[j] = roboStack.top();
						//Above75.pop_front();
						while( roboStack.size() != 0 )
						{
							Above75.push_front(roboStack.top());
							roboStack.pop();
						}
					}
					else
					{
						j--;
					}
				}
				else if( probability >=30 ) //If the probability is greater than 25% but less than 50%, take from the Above50 list
				{
					if( Above50.size() != 0 )
					{
						for( int i = abs((double)(mR()%Above50.size())); i >= 0; i-- ) //!!!!!!!!!!Not sure what this does exactly!!!!!!!!!!
						{															  //!!!!!!!!!!Not sure what this does exactly!!!!!!!!!!
							roboStack.push(Above50.front());						  //!!!!!!!!!!Not sure what this does exactly!!!!!!!!!!
							Above50.pop_front();//!!!!!!!!!!Not sure what this does exactly!!!!!!!!!!
						}															  //!!!!!!!!!!Not sure what this does exactly!!!!!!!!!!
						robot[j] = roboStack.top();
						//Above50.pop_front();
						while( roboStack.size() != 0 )
						{
							Above50.push_front(roboStack.top());
							roboStack.pop();
						}
					}
					else
					{
						j--;
					}
				}
				else if( probability >=10 ) //If the probability is greater than 10% but less than 25%, take from the Above25 list
				{
					if( Above25.size() != 0 )
					{
						for( int i = abs((double)(mR()%Above25.size())); i >= 0; i-- )	//!!!!!!!!!!Not sure what this does exactly!!!!!!!!!!
						{																//!!!!!!!!!!Not sure what this does exactly!!!!!!!!!!
							roboStack.push(Above25.front());							//!!!!!!!!!!Not sure what this does exactly!!!!!!!!!!
							Above25.pop_front();										//!!!!!!!!!!Not sure what this does exactly!!!!!!!!!!
						}																//!!!!!!!!!!Not sure what this does exactly!!!!!!!!!!
						robot[j] = roboStack.top();
						//Above25.pop_front();
						while( roboStack.size() != 0 )
						{
							Above25.push_front(roboStack.top());
							roboStack.pop();
						}
					}
					else
					{
						j--;
					}
				}
				else //If the probability is greater than 0% but less than 10%, take from the Rest list
				{
					if( Rest.size() != 0 )
					{
						for( int i = abs((double)(mR()%Rest.size())); i >= 0; i-- )	//!!!!!!!!!!Not sure what this does exactly!!!!!!!!!!
						{															//!!!!!!!!!!Not sure what this does exactly!!!!!!!!!!
							roboStack.push(Rest.front());							//!!!!!!!!!!Not sure what this does exactly!!!!!!!!!!
							Rest.pop_front();										//!!!!!!!!!!Not sure what this does exactly!!!!!!!!!!
						}															//!!!!!!!!!!Not sure what this does exactly!!!!!!!!!!
						robot[j] = roboStack.top();
						//Rest.pop_front();
						while( roboStack.size() != 0 )
						{
							Rest.push_front(roboStack.top());
							roboStack.pop();
						}
					}
					else
					{
						j--;
					}
				}

			}
		}
		while(robot[0] == robot[1]);
		mate(robot[0], robot[1]); //Mate the first two Robots
	}

	
}


void RoboGeneration::naturalSelection(void)
{
	//mpopulation.sort();
	list<Phenotype> templist;
	list<Phenotype*>::iterator it = mpopulation.begin(); 
	while (it != mpopulation.end())
	{
		templist.push_back(*(*it)); //Takes the DNA(which also points to the fitness) and puts it in a temporary list
		it++;
	}
	templist.sort(); //Sorts the fitness from least to greatest
	//mpopulation.reverse();
	templist.reverse(); //Makes the list go from greatest to least
	mpopulation.clear(); //clears the initial population
	for( int i = 0; i < (Terminator/2); i++) //goes until half of the population
	{
		Phenotype temp = templist.front();		//puts the DNA into a temporary Phenotype object
		mpopulation.push_back(new Robot(temp)); //then puts DNA into a new robot into the initial population
		templist.pop_front();					//then pops the first robot from the temporary list
	}
}



list<Phenotype*>* RoboGeneration::getPopulation()
{
	return &mpopulation;
}

void RoboGeneration::mate( Phenotype a, Phenotype b ) //!!!!!!!!!!!!Logic is currently wrong needs to be a random place!!!!!!!!!!!!
{
	random_device mR;
	int Ran1 = mR()%243;
	string DNA1 =  a.reproduce(0,Ran1);
	string DNA2 =  b.reproduce(Ran1+1, 242);
	string DNA3 = a.reproduce(Ran1+1,242);
	string DNA4 = b.reproduce(0,Ran1);
	string DNA5 = DNA1 + DNA2;
	string DNA6 = DNA4 + DNA3;
	Robot r1 = Robot(DNA5);
	r1.mutate();
	Robot r2 = Robot(DNA6);
	r2.mutate();
	mpopulation.push_back(new Robot(r1)); //Takes the 1st DNA strand to the random index and adds the 2nd DNA strand from the index to the end
	mpopulation.push_back(new Robot(r2)); //Takes the 2nd DNA strand to the random index and adds the 1st DNA strand from the index to the end

}