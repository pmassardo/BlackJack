/** Hand.h
 *	
 *	The Hand.h file represents a player's card hand.   
 *
 *   
 *	@author		P. Massardo
 *	@version	2014.01
 *  @description Hand.h represents a player's hand. It is a container class for the standard playing card. 
 				 Each player can have upto two hands in the evnt of a split. The hand has a number of functions
 				 to facilitate geting and setting value, as well as, determining when a had is done.
				
 *	@since		December 2014
*/

#ifndef _STD_HAND
#define _STD_HAND

#include <iostream>
#include <deque>
#include <algorithm> 
#include <iomanip>
#include "StandardPlayingCard.h"

using namespace std;

class Hand  : public StandardPlayingCard
{
	
	public:
	
		/* 
			AcceptCard 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	displays a nicely formatted hand	
			@param			NA
			@return			NA
		*/	
		//virtual void AcceptCard(StandardPlayingCard&);
		
	 	virtual StandardPlayingCard GetCard(int cardIndex) {return myCards[cardIndex];};
	 	
	 	
	 	/* 
			GetIsSoft 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	returns if the current hand is soft	
			@param			NA
			@return			bool - is the current hand soft
		*/	 	
	 	bool GetIsSoft() const {return myIsSoft;};
	 	
	 	/* 
			GetNumberOfCards 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	returns the number of cards in the current hand	
			@param			NA
			@return			bool - is the current hand soft
		*/		 	
	 	int GetNumberOfCards() const {return myCards.size();};

	 	
	 	/* 
			DisplayHand 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	displays a nicely formatted hand	
			@param			NA
			@return			string - returns the current hand 
		*/	 	
	 	string DisplayHand()  ;
	 	
	 	/* 
			FaceUpAllCards 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	set the faceup switch to true for all cards in the dealers hand		
			@param			NA
			@return			NA
		*/		
		void FaceUpAllCards();
	 	
	 	/* 
			Value 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	gets the numeric value of a hand		
			@param			bool - set to false if you want the total value regardless of face up or face down
			@param			bool - counts the ace as an eleven rather than a one			
			@return			int - the total value of the hand
		*/	
	 	//int GetValue(bool onlyFaceUp=true,bool countAceAsEleven=true);
	 	int Value(bool onlyFaceUp=true,bool countAceAsEleven=true);
	 		 	
	 	/* 
			GetValue 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	gets the numeric value of a hand but only for cards face up	and treats ace a one	
			@param			NA
			@return			int - the total value of the hand
		*/	 	
	 	virtual int GetValue();
	 	
	 	/* 
			IsCurrentDeckSoft 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	checks to see of the current hand is soft by getting the value of the hand
							and count any aces as elevens	
			@param			NA
			@return			bool - true if soft false if hard
		*/
	 	bool IsCurrentHandSoft();
	 	
	 	/* 
			PlaceBet 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	set the bet in whole dollars	
			@param			int - amount in whole dollars
			@return			void
		*/	
	 	void PlaceBet(int amountInWholeDollars){myBet=amountInWholeDollars;};
 	
 	 	/* 
			GetBet 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	get the bet in whole dollars	
			@param			NA 
			@return			int - amount in whole dollars
		*/	
	 	int GetBet() const {return myBet;};
	 	
	 	/* 
			DoubleDown 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	allows the doubling of a bet upto 100% of the current bet
							will not allow any more that 100% or double of the original
							bet. it will also set the indicator to show that the had has
							been double downed.	
			@param			int - amount in whole dollars
			@return			void
		*/	
	 	virtual void DoubleDown(int amountInWholeDollars);

	 	/* 
			Hit 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	adds a card to the hand.	
			@param			StandardPlayingCard - new card
			@return			void
		*/
		virtual void Hit(StandardPlayingCard card);
		
		Hand(int bet = 0, bool isSoft=false, bool isDoubleDown=false, bool isAllowedToSurrender=true, bool isAllowedToHit=true, bool isBust=false, bool isHandOkToPlay=true) : myBet(bet), myIsSoft(isSoft), myIsDoubleDown(isDoubleDown),myIsAllowedToSurrender(isAllowedToSurrender), myIsAllowedToHit(isAllowedToHit), myIsBust(isBust), myIsHandOkToPlay(isHandOkToPlay) {}

		/* 
			GetIsDoubleDown 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	returns if the current hand has double downed earlier	
			@param			NA
			@return			bool - is the current hand has double downed earlier
		*/	 	
	 	bool GetIsDoubleDown() const {return myIsDoubleDown;};

		/* 
			GetIsDoubleDown 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	returns if the current hand is allowed to hit	
			@param			NA
			@return			bool - is the current hand is allowed to hit
		*/	 	
	 	bool GetIsAllowedToHit() const {return myIsAllowedToHit;};

		/* 
			GetIsAllowedToSurrender 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	returns if the current hand is allowed to hit	
			@param			NA
			@return			bool - is the current hand is allowed to hit
		*/	 	
	 	bool GetIsAllowedToSurrender() const {return myIsAllowedToSurrender;};

		/* 
			GetIsBust 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	returns if the current hand is a bust	
			@param			NA
			@return			bool - is the current hand is a bust
		*/	 	
	 	virtual bool GetIsBust() const {return myIsBust;};
	 	
	 			/* 
			GetIsBust 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	returns if the current hand is a bust	
			@param			NA
			@return			bool - is the current hand is a bust
		*/	 	
	 	virtual void SetIsBust(bool isBust) {myIsBust=isBust;};
	 	
	 	/* 
			GetIsHandOkToPlay 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	returns if the current hand is a okay to continue	
			@param			NA
			@return			bool - returns if the current hand is a okay to continue
		*/	 	
	 	virtual bool GetIsHandOkToPlay() const {return myIsHandOkToPlay;};
	 	
	 	/* 
			SetIsHandOkToPlay 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	sets of the hand is okay to continue	
			@param			bool - sets of the hand is okay to continue
			@return			NA 
		*/	 	
	 	virtual void SetIsHandOkToPlay(bool isHandOkToPlay) {myIsHandOkToPlay=isHandOkToPlay;};
	 	

	 	/* 
			GetHandKey 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	gets the key of the current hand	
			@param			string - current hand key
			@return			NA 
		*/	 	 	
	 	string GetHandKey(int dealerHandValue);


 	
 	private:
 		
 		deque<StandardPlayingCard> myCards;	
 		
 		bool myIsHandOkToPlay;
 		
		bool myIsSoft;
 		
 		bool myIsBust;
 		
		int myBet;

 		// if it is a double down you are only 
		// allowed one more hit
 		bool myIsDoubleDown;
 		
 		// you are only allowed to surrender if
 		// you have not done anything after the deal
 		// split, doubledown, hit
 		bool myIsAllowedToSurrender;
 		
 		// lets the palyer no if any more plays can happen
 		bool myIsAllowedToHit;
 			
};

void Hand::DoubleDown(int amountInWholeDollars)
{
	
	if (myBet>amountInWholeDollars)
	{
		
		myBet += amountInWholeDollars;
		
	}
	else
	{
		myBet += myBet;
	}
	
	myIsAllowedToSurrender = false;
	
}

void Hand::Hit(StandardPlayingCard newCard)
{
	
	// get the current hand value counting any aces as elevens
	int currentHandValue = Value(false,true);
	
	// if the new card is an ace or one and
	// the total of the current hand plus the
	// new card is less than or equal to 21
	// then the hand is soft, so set the 
	// boolean to true
	if ((newCard.getRankValue()==1) and ((currentHandValue+newCard.getRankValue())<=21))
	{
		myIsSoft=true;		
	}
	else
	{
		myIsSoft=false;	
	}
	

		
	// add the card to the deque
	myCards.push_back(newCard);
	
	// if the player has gotten any more than
	// two cards they are not allowed to surrender
	if(myCards.size()>2)
	{
		
		myIsAllowedToSurrender = false;
		
	}
	
	// get the current hand value counting any aces as ones
	currentHandValue = Value(false,false);
		
	if (currentHandValue>21)
	{
		myIsHandOkToPlay=false;
		myIsBust=true;		
	}
	
}

bool Hand::IsCurrentHandSoft()
{
	bool returnValue = false;
	int currentHandValue = Value(false,true);
	
	// if there is an ace in the deck
	// and the combination of all cards
	// with the ace counted as a value of 
	// 11 is less tha 21 then the hand is 
	// soft
	if (currentHandValue> 21)
	{
		returnValue=true;
	}	
	
	// else if the the hand with an ace
	// is over 21 when the ace is counted 
	// as a 11 then the hand is hard
	
	return returnValue;
	
}

int Hand::GetValue() 
{	
	int returnValue;
	
	if(IsCurrentHandSoft())
	{
		returnValue = Value(true, true);
	}
	else
	{
		returnValue = Value(true, false);
	}

	return 	returnValue;
}


int Hand::Value(bool onlyFaceUp,bool countAceAsEleven)
{
	int returnValue=0;
	int currentValue=0;
	int aceCount =0;
	
	deque<StandardPlayingCard>::iterator it;

	for(it = myCards.begin(); it != myCards.end(); ++it)
	{
		if(((*it).isFaceUp==true) or (onlyFaceUp==false))
		{

			currentValue = (*it).getRankValue();
			
			// if the current value is one or an ace
			// and we want to count the ace as an 
			// eleven instead of a one then set it 
			// too eleven
			// and the ace count is zero, 
			// so only count the first ace as elevn
			if((currentValue==1) and(countAceAsEleven==true) and (aceCount==0))
			{
				currentValue = 11;
				aceCount = 1;
				
			}
			else if((currentValue>=10))
			{
				// if the current card is a king 
				// queen or jack return a 10
				currentValue = 10;
			}
			
			returnValue  += currentValue;
		
		}

	}
	
	return returnValue;	
}

string Hand::GetHandKey(int dealerHandValue)
{
	int currentValue=0;
	int aceCount =0;
	int cardCount = myCards.size();	
	int duplicateCard = 0;
	int count = 0;
	bool duplicateExist=false;
	stringstream strOut;
	int runningTotal=0;
	
	deque<StandardPlayingCard>::iterator it;	

	for(it = myCards.begin(); it != myCards.end(); ++it)
	{
			
		// if the current card is a king 
		// queen or jack return a 10
		currentValue = (*it).getRankValue();	
			
		// if the current value is one or an ace
		// and we want to count the ace as an 
		// eleven instead of a one then set it 
		// too eleven
		// and the ace count is zero, 
		// so only count the first ace as elevn
		if((currentValue==1) and (aceCount==0))
		{
			aceCount = 1;
			
		}
		else 
				{
			// if the current card is a king 
			// queen or jack return a 10
			runningTotal += (((*it).getRankValue()>10)?10:(*it).getRankValue());
		}
		
		// check for duplicates only 
		// if it is the first hand
		// so only two cards
		if(cardCount==2)
		{
			//check for duplicates
			if(count==0)
			{
				// assign the first card to the duplicate variable
				 duplicateCard = (*it).getRankValue();
			}
			else
			{
				
				// the second time through check if the
				// current value is the same as the one
				// in the duplicateCard variable
				if(duplicateCard==(*it).getRankValue())
				{
					// if so the first two cards
					// are duplicates
					duplicateExist = true;
					
				}					
				
			}
			
		}
		
		count++;

	}
	
	// create the key	
	if((duplicateExist==true) and (cardCount== 2))
	{
		
//		strOut << "2" << duplicateCard << duplicateCard << dealerHandValue;
		strOut << "2" << setfill('0') << setw(2) << duplicateCard << setfill('0') << setw(2) << dealerHandValue;
		
	}
	else if((aceCount==1) and (duplicateExist==false) and (cardCount== 2))
	{		
		//strOut << "1" << "0" << runningTotal << dealerHandValue;
		strOut << "1" << setfill('0') << setw(2) << runningTotal << setfill('0') << setw(2)  << dealerHandValue;
	}
	else
	{
		//setfill('0') << setw(5) <<
		strOut << "0" << setfill('0') << setw(2) << runningTotal << setfill('0') << setw(2) << dealerHandValue;
	}
	
	
	return strOut.str();	
}


string Hand::DisplayHand() 
{
	// declare a stringstream object
	stringstream strOut; 
	
	deque<StandardPlayingCard>::iterator it;

	for(it = myCards.begin(); it != myCards.end(); ++it)
	{
		if ((*it).isFaceUp==true)
		{
			strOut << string((*it)) << endl;			
		}
		else
		{
			strOut << "Face Down Card" << endl;
		}
		

	}
	
	// return the string
	return strOut.str();

}

void Hand::FaceUpAllCards()
{

	deque<StandardPlayingCard>::iterator it;

	for(it = myCards.begin(); it != myCards.end(); ++it)
	{
		(*it).isFaceUp=true;

	}

}

#endif



