#include "RoboGeneration.h"
#include "RoboEvaluator.h"
#include "GA.h"


int main(void)
{
	RoboEvaluator robotTest;
	RoboGeneration robotContainer = RoboGeneration(Terminator);
	GA geneticAlgorithm = GA(robotTest, robotContainer);
	geneticAlgorithm.start(1000);
	system("pause");
}
