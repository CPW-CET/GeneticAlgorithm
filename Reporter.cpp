//Reporter.cpp
#include "Reporter.h"

void Reporter::reportGeneration(string P)
{
	//string GetDNA = P->getDNA(); //Gets the DNA
	//int Score = P->getFitness(); //Gets the Score for the DNA
	string mFileName = "GenerationData.txt"; //Makes the name of the .txt file
	ofstream myfile (mFileName); //Opens and creates the .txt file
	if (myfile.is_open())						// If the file is open, proceed
	{											//Output is somewhat like this !!!!!Needs to be changed!!!!! 
		myfile << "Score\n";					//Score
		//myfile << Score << endl;				//
		myfile << P;
	}											//   .	   
		myfile.close();							// Closes File
	string mFileName2 = "Generation.txt";
	ofstream myfile2 (mFileName2);
	if (myfile2.is_open())						// If the file is open, proceed
	{											//Output is somewhat like this !!!!!Needs to be changed!!!!! 
		myfile2 << "Generation\n";				//Generation
		for(int i = 0; i < 1000; i++)			//1     
		{										//2	   
			myfile2 << i+1 << endl;				//.	   
												//.	   
		}										//1000	   (Does the same score 1000 times)
		myfile2.close();						// Closes File
	}
}

void Reporter::Save(string FileName, string DNA) //Wasn't sure what to pass it alongside a file name, most likely passing DNA so a string?
{
	ofstream myfile (FileName);	//Opens and creates the .txt file
	if (myfile.is_open())
	{
		myfile << DNA << endl; //Puts the DNA into the .txt file
		myfile.close();		   //Closes the file
	}
}

string Reporter::Load(string FileName)
{
	string line;
	stringstream filedata;
	ifstream myFile (FileName); //Opens the file that is requested
	if (myFile.is_open()) //Checks to see if said file exists
	{
		while (myFile.good()) //If its good, then procedd
		{
			getline(myFile,line); //gets the Line
			filedata << line << endl; //and puts it into a stringstream
		}
		myFile.close(); //Closes the File
	}
	return filedata.str(); //Changes the stringstream into a string and returns
}