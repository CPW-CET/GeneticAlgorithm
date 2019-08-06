#pragma once
#include "Evaluator.h"
#include "Board.h"
#include "TileType.h"
#include "Point.h"
#include "Robot.h"
#include <cmath>
#include <random>

class RoboEvaluator : public Evaluator
{
private:
	Board mBoard[100];
	std::random_device mR;
public:
	RoboEvaluator();
	~RoboEvaluator();

	// publicly called evaluate function
	void evaluate( list<Phenotype*>* G );
private:


	// calls simulate for each robot in the generation
	// then creates a new board and repeats the process
	virtual void evaluateHelper( Phenotype *current,int j, bool First );

	// uses P to find the position on the board 
	// returns the DNA index for the situation at that position
	int getSituation( CPoint P, Board pBoard );

	// makes 200 moves for the robot
	// edits the board per robot instructions
	// therefore a board copy must be made
	void simulate( Phenotype *pRobot, Board pBoard );
};