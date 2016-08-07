/*  Dealer.h
 *	
 *	A class representing a Dealer of one or more standard deck(s) of StandardPlayingCard.
 *	@author		P. Massardo
 *	@version	2014.01
 *  @description This class will allow extending the StandardPlayingCard class and allow play with multiple decks.
 				 This class is derived from the StandardPlayingCard class
 				 It gives the ability to initialize, shuffle, drawnext and draw random as well allowing
 				 for a copy constructor and and assignment operator.
 				 The Dealer class is essentially a card shoe with a little logic to end the dealers play and 
				 it also has a hand. 
 *	@since		Oct 2014
 *
*/

#ifndef _STD_DEALER
#define _STD_DEALER

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <time.h>
#include <string> 
#include "StandardPlayingCard.h"
#include "Hand.h"

using namespace std;

//namespace myCardShoe_v1 // namespace
//{

class Dealer : public StandardPlayingCard
{
	
	private:
		
		const int WHEN_TO_HIT=17;
		
		// variables
		StandardPlayingCard * myCards;
		int myNumberOfDecks = 0;
		int myCurrentCardCount = 0;	

	 	string myName;
		Hand * myHands; 
		int myNumberOfHands=0;
			
		
		// constants (currently this does not work it is intended for the final project)	
		const int NUMBER_OF_DECKS_MODULUS_DENOMINATOR = 2;

		/* 
			ValidDateNumberOfDecks - function 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	Validates that the number passed in is an 
							appropriate number of decks	
							(currently this does not work it is intended for the final project)						
			@param			int - numberOfDecks
			@return			NA
		*/
		bool ValidDateNumberOfDecks(int);
		
	public:
	
		//void split();
		
		string getName() const { return myName;};
	
		//virtual void Hit();
	 	virtual void AcceptCard(StandardPlayingCard&);
	 	virtual int GetHandValue();
	 	virtual int GetNumberOfHands() const  {return myNumberOfHands;};
	 	string DisplayHand() ;
		
		
		/* 
			Dealer - 	constructor 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	Constructor for the Dealer			
			@param			NA
			@return			NA
		*/
		Dealer(int numberOfDecks = 1);
		
		/* 
			Dealer -  copy constructor 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	creates a copy of another class upon creating a new class based on an existing class.			
			@param			Dealer
			@return			NA
		*/			
		Dealer(const Dealer &source); // NEW! copy constructor

		/* 
			~Dealer - destructor 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	releases the memory for the underlying array of Dealer			
			@param			NA
			@return			NA
		*/	
		~Dealer() { delete [] myCards;} // destructor		
		
		/* 
			Initialize 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	function to reset the deck to its original state 52 cards and number of desk specified			
			@param			int - number of standard decks in the card shoe
			@return			NA
		*/	
		virtual void Initialize(int);
		
		/* 
			PopOff 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	function to remove and element of an array based on the index provided			
			@param			int - index to remove
			@return			NA
		*/
		void PopOff(int);
		
		/* 
			CardsRemaining 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	returns the number (int) of StandardPlayingCards remaining			
			@param			NA
			@return			int
		*/		
		int CardsRemaining() const {return myCurrentCardCount;};
		
		/* 
			[] const 
			@author 		T. MacDonald
			@copy replace	P. Massardo
			@since			31-Oct-2014
			@description	returns a StandardPlayingCard based on the index specified		
			@param			NA
			@return			StandardPlayingCard
		*/		
		StandardPlayingCard operator[](int index) const;  // accessor version of []
		
		/* 
			[] 
			@author 		T. MacDonald
			@copy replace	P. Massardo
			@since			31-Oct-2014
			@description	returns a reference StandardPlayingCard based on the index specified			
			@param			NA
			@return			StandardPlayingCard
		*/
		StandardPlayingCard& operator[](int index);		  // mutator version of []
		
		/* 
			Overloaded Assignment Operator 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	assign a class to an alreay existing class.			
			@param			Dealer&
			@return			Dealer&
		*/	
		Dealer& operator=(const Dealer &source); // assignment operator	


		/* 
			DrawNextCard 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	returns the next StandardPlayingCard from the class level array			
			@param			NA
			@return			StandardPlayingCard
		*/
		virtual StandardPlayingCard DrawNextCard();
		
		/* 
			DrawRandomCard 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	returns a random StandardPlayingCard from the class level array			
			@param			NA
			@return			StandardPlayingCard
		*/
		StandardPlayingCard DrawRandomCard();
		
		/* 
			Shuffle 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	randomly shuffles the Dealer using swap			
			@param			NA
			@return			NA
		*/
		void Shuffle();	
		
		/* 
			OkToHit 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	decides what the dealer should do based on the current hand			
			@param			NA
			@return			bool - decision
		*/
		bool OkToHit();	

		/* 
			FaceUpAllCards 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	set the faceup switch to true for all cards in the dealers hand		
			@param			NA
			@return			na
		*/		
		void FaceUpAllCards();
		/* 
			Hit 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	set the faceup switch to true for all cards in the dealers hand		
			@param			bool - hide tha card or not
			@return			NA
		*/		
		virtual void Hit(bool isHideCard);		

		/* 
			ResetHand 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	resets the dealer hand to empty		
			@param			NA
			@return			NA
		*/		
		void ResetHand();
		
		/* 
			GetIsHandBust - 	function 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	is the current hand a bust
			@param			NA			
			@return			bool - is the current hand a bust
		*/
		bool GetIsHandBust();
	
};

//	myNumberOfHands = numberOfHands;
//	myHands = new Hand[numberOfHands];

// constructor
Dealer::Dealer(int numberOfDecks)
{

	// set the card array to zero
	myCards = 0;
	myHands = 0;
	
	// call the initialize method 
	Initialize(numberOfDecks);

}


void Dealer::Initialize(int numberOfDecks) {
	
	if(Dealer::ValidDateNumberOfDecks(numberOfDecks))
	{
		
		// check if the pointer is set to zero
		if (myCards != 0)
		{		
			// if so release the memory allocation
			delete [] myCards;
		}
		
		// check if the pointer is set to zero
		if (myHands != 0)
		{		
			// if so release the memory allocation
			delete [] myHands;
		}
		
		// create a new hand
		// initialize to one because the
		// dealer will only have one hand		
		myHands = new Hand[1];
				
		// Allocate a new array dynamically on construction
		myCards = new StandardPlayingCard [(((StandardPlayingCard::MAX_SUIT+1)*StandardPlayingCard::MAX_RANK)*numberOfDecks)]; // may throw bad_alloc exception
		myCurrentCardCount = 0;
		
		for(int currentDeck=0;currentDeck<numberOfDecks;currentDeck++) 	
		{
			
			// Initialize each element to the initial value
			// loop through the possible suits and set them
			for(int currentSuit = 0; currentSuit <= StandardPlayingCard::MAX_SUIT; currentSuit++)
			{		
			
				// loop through the possible ranks
				for(int currentRank = 1; currentRank <= StandardPlayingCard::MAX_RANK; currentRank++)
				{
					
					// set the suit
					myCards[myCurrentCardCount].setSuit(currentSuit);
					
					// set the rank
					myCards[myCurrentCardCount].setRank(currentRank);
					
					// increment the card counter
					myCurrentCardCount++;
					
				}		
			
			}
			
		}
		
	}
	
}

bool Dealer::ValidDateNumberOfDecks(int numberOfDecks) {
	
	// this will be used more extensively in the final project
	
	bool returnValue=true;
	
	if(numberOfDecks>0)
	{
		returnValue=true;
	}
	
	
	return returnValue;
}

StandardPlayingCard Dealer::operator[](int index) const
{
	// if the parameter index is invalid, throw an exception
	if(index < 0 || index >= myCurrentCardCount)
	{
		throw out_of_range("Index must be between 0 and " + std::to_string(myCurrentCardCount - 1) + ".");
	}
		
	// return the value stored at element index
	return myCards[index]; 
}	

// operator [] accessor for an element of myArray
StandardPlayingCard& Dealer::operator[](int index)
{
	// if the parameter index is invalid, throw an exception
	if(index < 0 || index >= myCurrentCardCount)
	{
		throw out_of_range("Index must be between 0 and " + to_string(myCurrentCardCount - 1) + ".");
	}
		
	// return the value stored at element index
	return myCards[index]; 
}	


// assignment operator
Dealer& Dealer::operator=(const Dealer &source)
{
	delete [] myCards; // free up the old memory
	
	// Allocate a new array dynamically on construction
	myCurrentCardCount = source.myCurrentCardCount; // set the size
	
	myCards = new StandardPlayingCard[myCurrentCardCount]; // may throw bad_alloc exception
	
	// Initialize each element to the corresponding value in the source object
	for(int i = 0; i < myCurrentCardCount; i++)
	{
	
		myCards[i] = source.myCards[i];
		
	}
	
	return *this;
} 

// copy constructor
Dealer::Dealer(const Dealer &source)
{
	// Allocate a new array dynamically on construction
	myCurrentCardCount = source.myCurrentCardCount; // set the size
	
	myCards = new StandardPlayingCard[myCurrentCardCount]; // may throw bad_alloc exception
		
	// Initialize each element to the corresponding value in the source object
	for(int i = 0; i < myCurrentCardCount; i++)
	{
	
		myCards[i] = source.myCards[i];
		
	}	
		
}

void Dealer::PopOff(int cardToRemoveIndex) 
{
	
	// create a temp array
	StandardPlayingCard * tempArray = new StandardPlayingCard[(myCurrentCardCount-1)];
	
	// declare and initialize the offset
	int offSet = 0;
	
	// iterate through the current array
	for(int index = 0; index < myCurrentCardCount-1; index++)
	{
		// add the old array data except 
		// for the element at the cardToRemoveIndex
		if(cardToRemoveIndex==index)
		{
			
			// set the offset
			offSet=1;	
		
		}
		
		// set the element in the temp array
		tempArray[index] = myCards[index+offSet];
		
	}
	
	// release the memory of the class level array
	delete  [] myCards;
	
	// set the class level array to the temp array
	myCards = tempArray;

	// lower the size variable by one	
	myCurrentCardCount--;
		
}

StandardPlayingCard Dealer::DrawRandomCard() 
{
	
	srand (time(NULL));

	int indexCardToDraw = rand() % myCurrentCardCount;
	
	// assign the first card to the tempCard
	StandardPlayingCard tempCardArray = myCards[indexCardToDraw];
	
	// pop the first card off the front of the deck
	PopOff(indexCardToDraw);
	
	// return the first card on the deck (position 0)
	return tempCardArray;
	
}

StandardPlayingCard Dealer::DrawNextCard() 
{

	// assign the first card to the tempCard
	StandardPlayingCard tempCard = myCards[0];
	
	// pop the first card off the front of the deck
	PopOff(0);	
	
	// return the first card on the deck (position 0)
	return tempCard;
	
}


void Dealer::Shuffle() 
{

	// standard playing card declaration
	StandardPlayingCard tempCardOne;

	// seed the rand
	srand (time(NULL));

	// declare an index to store the random number
	int indexCardToDraw;
	
	for(int index = 0; index< myCurrentCardCount; index++)
	{
		
		// assign the random number
		indexCardToDraw = rand() % myCurrentCardCount;
		
		// set the temp variable
		tempCardOne = myCards[index];
	
		// assign the value in the random index
		// to the loops index
		myCards[index] = myCards[indexCardToDraw];
		
		// assign the card in the temp value
		// to the value in the element at the 
		// random index
		myCards[indexCardToDraw] = tempCardOne;
		
	}	
	
}

void Dealer::Hit(bool isHideCard)
{
	StandardPlayingCard newCard	= DrawNextCard();
	
	if(isHideCard==true)
	{
		newCard.flipCard();
	}
	
	myHands[0].Hit(newCard);
}

void Dealer::AcceptCard(StandardPlayingCard& newCard)
{

	myHands[0].Hit(newCard);	
	
}

int Dealer::GetHandValue()
{
	int returnValue;
	int softValue = myHands[0].Value(true,false);
	int hardValue = myHands[0].Value(true,true); 
	
	if((softValue==hardValue) or (hardValue>21))
	{
		returnValue=softValue;
	}
	else 
	{	
		returnValue=hardValue;
	}
	return returnValue; //myHands[0].GetValue();

}

string Dealer::DisplayHand() 
{
	
	// declare a stringstream object
	stringstream strOut; 

	strOut << "\n-------------------" << endl;
	strOut << "Dealer's Hand" << endl;
	strOut << myHands[0].DisplayHand();
	strOut << "Hand soft value showing " << myHands[0].Value(true,false) << endl;
	strOut << "Hand hard value showing " << myHands[0].Value(true,true) << endl;
	strOut << "-------------------" << endl;
	
	return  strOut.str();
	
}

bool Dealer::OkToHit()
{
	
	int handValue = myHands[0].Value(false,false);
	bool hit=false;
	
	if(handValue<WHEN_TO_HIT)
	{
		hit=true;
	}
	
	return hit;	
	
}

void Dealer::FaceUpAllCards()
{

	myHands[0].FaceUpAllCards();
	
}

void Dealer::ResetHand()
{
	
	delete  [] myHands;
	myNumberOfHands = 1;
	myHands = new Hand[myNumberOfHands];
	
}
bool Dealer::GetIsHandBust()
{

	return myHands[0].GetIsBust();

}

#endif
