#include "RoboEvaluator.h"
#include <iostream>

RoboEvaluator::RoboEvaluator() : Evaluator()
{
	for( int i = 0; i < 100; i++ ) //Making 100 Boards
	{
		mBoard[i] = Board();
	}
}

RoboEvaluator::~RoboEvaluator()
{

}

void RoboEvaluator::evaluate( list<Phenotype*>* G )
{
	list<Phenotype*>::iterator it = G->begin();
	int j = 0;
	static bool first = true;
	while( it != G->end() )
	{
		evaluateHelper(*it, j, first);
		it++;
		j++;
	}
	first = false;
}

void RoboEvaluator::evaluateHelper( Phenotype* current, int j, bool First )
{
	current->getFitness() = 0;
	for( int i = 0; i < 100; i++ ) //Simulates the 100 boards
	{
		simulate( current, mBoard[i] );
	}
	current->getFitness() = current->getFitness()/100; //Finds the average fitness
	static int i = 0;
	if(verbose2)
	{
		
		cout << "Robot: " << i+1 << endl;
		cout << "Fitness: " << current->getFitness() << endl;
		i++;
	}
}

int RoboEvaluator::getSituation( CPoint P, Board pBoard )
{
	int index = 0;
	if(verbose)
	{
		cout << " -North-  " << "-South-  " << "-East-  " << "-West-  " << "-Current- " << "-Move-" << endl;
	}
	// north tile
	switch( pBoard.getValue( (int)(P.X() - 1), (int)P.Y() ) )
	{

	case TileType::wall: //If the Tile to the North is a Wall
		index += 0;
		if( verbose )
		{
			cout << "  Wall ";
		}
		break;
	case TileType::can: //If the Tile to the North is a Can
		index += (int)pow(3.0,4);
		if( verbose )
		{
			cout << "   Can ";
		}
		break;
	case TileType::blank: //If the Tile to the North is Blank
		index += (int)(2*pow(3.0,4));
		if( verbose )
		{
			cout << " Blank ";

		}
		break;
	}
	// south tile
	switch( pBoard.getValue( (int)(P.X() + 1), (int)P.Y() ) )
	{
	
	case TileType::wall: //If the Tile to the South is a Wall
		index += 0;
		if( verbose )
		{
			cout << "     Wall ";
		}
		break;
	case TileType::can: //If the Tile to the South is a Can
		index += (int)pow(3.0,3);
		if( verbose )
		{
			cout << "     Can ";
		}
		break;
	case TileType::blank: //If the Tile to the South is Blank
		index += (int)(2*pow(3.0,3));
		if( verbose )
		{
			cout << "    Blank ";
		}
		break;
	}
	// east tile
	switch( pBoard.getValue( (int)P.X(), (int)(P.Y() + 1) ) )
	{

	case TileType::wall: //If the Tile to the East is a Wall
		index += 0;
		if( verbose )
		{
			cout << "  Wall ";
		}
		break;
	case TileType::can: //If the Tile to the East is a Can
		index += (int)pow(3.0,2);
		if( verbose )
		{
			cout << "    Can ";
		}
		break;
	case TileType::blank: //If the Tile to the East is Blank
		index += (int)(2*pow(3.0,2));
		if( verbose )
		{
			cout << " Blank ";
		}
		break;
	}
	// west tile
	switch( pBoard.getValue( (int)P.X(), (int)(P.Y() - 1) ) )
	{

	case TileType::wall: //If the Tile to the West is a Wall
		index += 0;
		if( verbose )
		{
			cout << "    Wall ";
		}
		break;
	case TileType::can: //If the Tile to the West is a Can
		index += (int)pow(3.0,1);
		if( verbose )
		{
			cout << "     Can ";
		}
		break;
	case TileType::blank: //If the Tile to the West is Blank
		index += (int)(2*pow(3.0,1));
		if( verbose )
		{
			cout << "   Blank ";
		}
		break;
	}
	//current position
	switch( pBoard.getValue( (int)P.X(), (int)P.Y() ) )
	{

	case TileType::wall: //If the Current Tile is a Wall
		index += 0;
		if( verbose )
		{
			cout << "    Wall " << endl;
		}
		break;
	case TileType::can: //If the Current Tile is a Can
		index += 1;
		if( verbose )
		{
			cout << "     Can ";
		}
		break;
	case TileType::blank: //If the Current Tile is Blank
		index += 2;
		if( verbose )
		{
			cout << "   Blank ";
		}
		break;
	}

	return index;
}

void RoboEvaluator::simulate( Phenotype* pRobot, Board pBoard )
{
	char sit;
	CPoint cPosition(0.0, 0.0);
	signed int cScore = 0;
	for( int i = 0; i < 200; i++ ) //Robot going through 200 actions per board
	{
		if (verbose)
		{
			std::cout << pBoard.ToString() << std::endl;
		}
		sit = pRobot->getAction(getSituation( cPosition, pBoard ));
		if (verbose)
		{
			std::cout<< "    " << moveOut[sit-'0'] << endl;
			std::cout << "Current Location: " << cPosition.X()+1 << ", " << (char)(cPosition.Y() + 'A') << endl;
			std::cout << "Current Score: " << cScore << endl;
		}
		
		switch( sit )
		{
		// move north
		case '0':
			if( pBoard.getValue( cPosition.X() - 1, cPosition.Y() ) == TileType::wall ) //Moving North and is a wall - 5 points
			{
				cScore -= 5;
			}
			else //Moving North if it is not a wall
			{
				cPosition.X() = cPosition.X() - 1;
			}

			break;
		// move south
		case '1':
			if( pBoard.getValue( cPosition.X() + 1, cPosition.Y() ) == TileType::wall ) //Moving South and is a wall -5 points
			{
				cScore -= 5;
			}
			else //Moving South if it is not a wall
			{
				cPosition.X() = cPosition.X() + 1;
			}
			//cout << "case 1 ";
			break;
		// move east
		case '2':
			if( pBoard.getValue( cPosition.X() , cPosition.Y() + 1 ) == TileType::wall ) //Moving East and is a wall -5 points
			{
				cScore -= 5;
			}
			else //Moving East if it is not a wall
			{
				cPosition.Y() = cPosition.Y() + 1;
			}
			break;
			//cout << "case 2 ";
		// move west
		case '3':
			if( pBoard.getValue( cPosition.X() , cPosition.Y() - 1 ) == TileType::wall ) //Moving West and is a wall -5 points
			{
				cScore -= 5;
			}
			else //Moving West if it is not a wall
			{
				cPosition.Y() = cPosition.Y() - 1;
			}
			//cout << "case 3 ";
			break;
		// stay put ---- Do Nothing
		case '4':
			//cout << "case 4 ";
			break;
		// pick up
		case '5':
			if( pBoard.getValue( cPosition.X(), cPosition.Y() ) == TileType::can ) //If picking up and there is a can +10 points
			{
				cScore += 10;
				pBoard.setValue( cPosition.X(), cPosition.Y(), false );
			} 
			else //If picking up and there isn't a can -1 point
			{
				cScore -= 1;
			}
			//cout << "case 5 ";
			break;
		// Random Move
		case '6':
			switch( (int)std::abs((float)(mR()%6))) //Randomly generates a move from 0-6 
			{
			// move north
			case 0:
				if( pBoard.getValue( cPosition.X() - 1, cPosition.Y() ) == TileType::wall ) //Moving North and is a wall - 5 points
				{
					cScore -= 5;
				}
				else //Moving North if it is not a wall
				{
					cPosition.X() = cPosition.X() - 1;
				}
				break;
			// move south
			case 1:
				if( pBoard.getValue( cPosition.X() + 1, cPosition.Y() ) == TileType::wall ) //Moving South and is a wall - 5 points
				{
					cScore -= 5;
				}
				else //Moving South if it is not a wall
				{
					cPosition.X() = cPosition.X() + 1;
				}
				break;
			// move east
			case 2:
				if( pBoard.getValue( cPosition.X(), cPosition.Y() + 1 ) == TileType::wall ) //Moving East and is a wall - 5 points
				{
					cScore -= 5;
				}
				else //Moving East if it is not a wall
				{
					cPosition.Y() = cPosition.Y() + 1;
				}
				break;
			// move west
			case 3:
				if( pBoard.getValue( cPosition.X(), cPosition.Y() - 1 ) == TileType::wall ) //Moving West and is a wall - 5 points
				{
					cScore -= 5;
				}
				else //Moving West if it is not a wall
				{
					cPosition.Y() = cPosition.Y() - 1;
				}
				break;
			// stay put ------ Do Nothing
			case 4:
				break;
			// pick up
			case 5:
				if( pBoard.getValue( cPosition.X(), cPosition.Y() ) == TileType::can ) //If picking up and there is a can +10 points
				{
					cScore += 10;
					pBoard.setValue( cPosition.X(), cPosition.Y(), false );
				}
				else //If picking up and there isn't a can -1 point
				{
					cScore -= 1;
				}
				break;
			default:
				break;
			}
		}
	}
	pRobot->getFitness() = (pRobot->getFitness() + (cScore)); //Adding the score to the Robot's Fitness
}