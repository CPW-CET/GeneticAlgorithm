#include "Board.h"

Board::Board()
{
	float cans = 50;
	float spaces = 100;
	std::random_device mR;
	for( int i = 0; i < 10; i++ )
	{
		for( int j = 0; j < 10; j++ )
		{
			int hi = (int)std::abs((float)(mR()%100));
			if( (cans/spaces)*100 > hi )
			{
				mBoard[i][j] = true;
				cans -= 1;
			}
			else
			{
				mBoard[i][j] = false;
			}
			spaces -= 1;
		}
	}
	if( verbose ){
		//std::cout << cans;
		//std::cout << spaces;
	}
}

Board::~Board()
{

}

TileType::tile Board::getValue(int x, int y)
{
	TileType::tile myTile = TileType::blank;
	if( ( x < 0 ) || ( x > 9 ) || ( y < 0 ) || ( y > 9 ) )
	{
		myTile = TileType::wall;
	}
	else if( mBoard[x][y] == true )
	{
		myTile = TileType::can;
	}
	return myTile;
}

void Board::setValue(int x, int y, bool b)
{
	mBoard[x][y] = b;
}

std::string Board::ToString(void)
{
	int size = 1;
	int row = 10;
	int column = 10;
	std::stringstream result;

	//Display captial letters across the top
	result << std::setw(2) << "   ";
	for (int i=0; i<column; i++)
	{
		result << std::setw(3) << char(i+65);
	}
	result << std::endl;

	//Display Top boarder
	result << std::setw(3) << "   ";
	for (int i=0; i<column; i++)
	{  
		if (i==0)
		{
			result << char(201);
		}
		else
		{
			result << char(205);
			result << char(209);
		}
		for (int j=0; j<1; j++)
		{
			result << char(205);
		}
	}
	result << char(205);
	result <<  char(187) << std::endl;

	// Display rows with data
	for (int i=0; i<row; i++)
	{
		//Display row numbers
		result << std::setw(2) << i+1 << " ";
		for (int j=0; j<column; j++)
		{
			//Display vertical lines
			if (j==0) 
			{
				result << char(186);
			}
			else
			{
				result << char(179);
			}
			if (mBoard==NULL)
			{
				result << std::setw(size+1) << "  ";
			}
			else
			{
				//Display logic
				if(mBoard[i][j] == true)
				{
					result << std::setw(size+1) << "C";
				}
				else
				{
					result << std::setw(size+1) << " ";
				}
			}
		}
		result << char(186) << std::endl; //Left hand border char

		//Display horizontal lines 
		result << std::setw(2) << "   ";
		for (int j=0; j<column; j++)
		{
			if ( i == row-1)
			{   
				//Display bottom boarder
				if (j==0)
				{
					result << char(200); // Left border char
				}
				else
				{
					//bottom connecter char
					result << char(207);
				}
				for (int k=0; k<1; k++)
				{
					result << char(205);
					result << char(205);

				}

			}
			else 
			{
				//Display internal dividers
				if ( j == 0)
				{
					result << char(199);
				}
				else 
				{
					// vertical lines on intermediate levels
					result << char(197);


				}

				for (int k=0; k<1; k++)
				{
										result << char(196);
					result << char(196);
				}
			}
		}
		if ( i == row-1)
		{
			result << char(188);
		}
		else
		{
			result << char(182) << std::endl;
		}
	}
	return result.str();
}
	
/*
int main()
{
	Board board[1];
	for( int i = 0; i < 1; i++)
	{
		board[i] = Board();
		std::cout << "BOARD NUMBER " << i+1 << std::endl;
		std::cout << board[i].ToString()<< std::endl;
	}
	system("pause");
}
*/