#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "Phenotype.h"
#include "Generation.h"

using namespace std;

class Reporter
{
private:
	string mFileName;
public:
	static void reportGeneration(string P);
	static void Save(string FileName, string DNA);
	static string Load(string FileName);
};