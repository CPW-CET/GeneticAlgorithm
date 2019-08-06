#include "Generation.h"
#include "Evaluator.h"
#include "Reporter.h"
#include "RoboEvaluator.h"
#include "RoboGeneration.h"

class GA
{
private:
	Evaluator* mE;
	Generation* mG;
public:
	GA(Evaluator& E, Generation& G);
	~GA();

	void start(int numberOfGenerations);
	void compare();
};