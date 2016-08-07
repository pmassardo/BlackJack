/** Intelligence.h
 *	
 *	The Intelligence.h file that represents a players desicion in the case of a computer player or a suggestion in the case of a human player.   
 *
 *   
 *	@author		M. Campo
 *	@modifications P. Massardo
 *	@version	2014.01
 *  @description Intelligence.h file that represents a players decision in the case of a computer player or a 
 				 suggestion in the case of a human player. The file is a wrapper for a map/char container. 
				It loads a file that is passed in and responds to data requests based on key values supplied
				by the hand object, based on the current hand of a player. 
				
 *	@since		December 2014
*/


#ifndef _STD_INTELLIGENCE
#define _STD_INTELLIGENCE

#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

class Intelligence 
{	
	public:
		
		/* 
			LoadIntelligence 
			@author 		M. Campo
			@modified 		P. Massardo
			@since			03-Dec-2014
			@description	loads a map container from a file with BlackJack Strategy								
			@param			string - file name of the file containing the BlackJack Strategy
			@return			NA
		*/
		void LoadIntelligence(string fileName);
		
		
		/* 
			GetIntelligence 
			@author 		M. Campo
			@modified 		P. Massardo
			@since			03-Dec-2014
			@description	returns a char value which indicates what a player should do. 
							(Hit, Stand, Split, Surrender, or DoubleDown)								
			@param			string - key value based on a card combination provided by the hand object/container.
			@return			char - character that represents a play
		*/
		char GetIntelligence(string handValueKey) const;
		
	private:
			
		// create a map
		map<string, char> brain;
		
};

char Intelligence::GetIntelligence(string handValueKey) const
{
	
	
	char returnValue;

	// if the is not at the and 
	if(brain.find(handValueKey)!=brain.end())
	{
		// get the value at the specified key
		returnValue = brain.at(handValueKey);
		
	}
	
	// return the value
	return 	returnValue;
		
}

void Intelligence::LoadIntelligence(string fileName)
{
	
	// variables
	ifstream inputFile;	
	string key;
	
	// open the input file			
	inputFile.open(fileName.c_str());
		
	// check to see if openning the file successfully
	if(inputFile.fail())
	{

		// Let the user know the file did not open successfully
		cout << fileName << " could not be opened for input. Please check that the file exits.";
		
	}
	else
	{
	
		// while we are not at the end of the file
		while(!inputFile.eof())
		{
			// check to see if the line is valid
			// and load the key
			if(inputFile >> key)
			{
			
				// load the current record/line of the file into the brain
				inputFile >> brain[key];
				
			}
		
		}
		
		// close the files			
		inputFile.close();
	
	}

}

#endif
