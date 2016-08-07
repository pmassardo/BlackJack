/** Players.h
 *	
 *	The Players.h file represents collection or container of players.   
 *
 *   
 *	@author		P. Massardo
 *	@version	2014.01
 *  @description Players.h represents a number of players. It has some functionality to allow
 				it to be used as an array. As well, it has some functionaly to treat the group
 				as a whole. As an example, ResetPlayersHands, with a single function call, will
 				reset all the hands for all the players.
				
 *	@since		December 2014
*/


#ifndef _STD_PLAYERS
#define _STD_PLAYERS

#include "Player.h"

class Players : public Player
{
	
	private:
		
		// variables
		Player * myPlayers;
		int myPlayerCount = 0;	
		
	public:
		
		/* 
			Players - 	constructor 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	Constructor for the CardShoe			
			@param			NA
			@return			NA
		*/
		Players(int numberOfPlayers = 1);
		
			/* 
			CardShoe -  copy constructor 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	creates a copy of another class upon creating a new class based on an existing class.			
			@param			Players
			@return			NA
		*/			
		Players(const Players &source); // NEW! copy constructor

		/* 
			~Players - destructor 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	releases the memory for the underlying array of Players			
			@param			NA
			@return			NA
		*/	
		~Players() { delete [] myPlayers;} // destructor	
		
				/* 
			[] const 
			@author 		T. MacDonald
			@copy replace	P. Massardo
			@since			31-Oct-2014
			@description	returns a Player based on the index specified		
			@param			NA
			@return			Player
		*/		
		Player operator[](int index) const;  // accessor version of []
		
		/* 
			[] 
			@author 		T. MacDonald
			@copy replace	P. Massardo
			@since			31-Oct-2014
			@description	returns a reference Player based on the index specified			
			@param			NA
			@return			Player
		*/
		Player& operator[](int index);		  // mutator version of []

		/* 
			GetPlayerCount
			@author 		P. Massardo
			@copy replace	P. Massardo
			@since			31-Oct-2014
			@description	returns the current number if players			
			@param			NA
			@return			Player
		*/
		int GetPlayerCount() const {return myPlayerCount;};		  		

		/* 
			GetActivePlayerCount
			@author 		P. Massardo
			@copy replace	P. Massardo
			@since			31-Oct-2014
			@description	returns the current number if players with cash in their chip banks			
			@param			NA
			@return			int - number of players
		*/
		int GetActivePlayerCount() const; 
		
		/* 
			ResetPlayersHands
			@author 		P. Massardo
			@copy replace	P. Massardo
			@since			31-Oct-2014
			@description	resets all the hands for all the players			
			@param			NA
			@return			NA
		*/
		void ResetPlayersHands(); 	
		
		/* 
			GetActiveHandCount
			@author 		P. Massardo
			@copy replace	P. Massardo
			@since			31-Oct-2014
			@description	returns the current number of non bust hands			
			@param			NA
			@return			int - number of non bust hands
		*/
		int GetActiveHandCount() const;
		
};

// constructor
Players::Players(int numberOfPlayers)
{

	
		// variables
		// if so release the memory allocation
		//delete [] myPlayers;
		myPlayerCount = numberOfPlayers;
		myPlayers = new Player[numberOfPlayers];


}

// copy constructor
Players::Players(const Players &source)
{
	// Allocate a new array dynamically on construction
	myPlayerCount = source.myPlayerCount; // set the size
	
	myPlayers = new Players[myPlayerCount]; // may throw bad_alloc exception
		
	// Initialize each element to the corresponding value in the source object
	for(int i = 0; i < myPlayerCount; i++)
	{
	
		myPlayers[i] = source.myPlayers[i];
		
	}	
		
}

Player Players::operator[](int index) const
{
	// if the parameter index is invalid, throw an exception
	if(index < 0 || index >= myPlayerCount)
	{
		throw out_of_range("Index must be between 0 and " + std::to_string(myPlayerCount - 1) + ".");
	}
		
	// return the value stored at element index
	return myPlayers[index]; 
}	

// operator [] accessor for an element of myArray
Player& Players::operator[](int index)
{
	// if the parameter index is invalid, throw an exception
	if(index < 0 || index >= myPlayerCount)
	{
		throw out_of_range("Index must be between 0 and " + to_string(myPlayerCount - 1) + ".");
	}
		
	// return the value stored at element index
	return myPlayers[index]; 
}
	
int Players::GetActivePlayerCount() const
{
	int activePlayerCount=0;
	bool isLoss;
	
	for(int index = 0; index < myPlayerCount; index++)
	{
		
		isLoss = myPlayers[index].GetIsLoss();
		
		if(isLoss==false)
		{
			activePlayerCount++;
		}
		
	}
	
	return activePlayerCount;
		
}

int Players::GetActiveHandCount() const
{
	int activeHandCount=0;
	bool isBust =false;
	int numberOfHands =0;
	
	for(int indexPlayer = 0; indexPlayer < myPlayerCount; indexPlayer++)
	{

		numberOfHands = myPlayers[indexPlayer].GetNumberOfHands();
		
			for(int indexHand=0; indexHand<numberOfHands;indexHand++)
			{
				
				isBust=	myPlayers[indexPlayer].GetIsHandBust(indexHand);
				
				if(isBust==false)
				{
					activeHandCount++;
				}
				
			}
		
	}
	
	return activeHandCount;
		
}


void Players::ResetPlayersHands()
{
	
	for(int index = 0; index < myPlayerCount; index++)
	{
		
		myPlayers[index].ResetHand();
		
	}

} 




#endif

