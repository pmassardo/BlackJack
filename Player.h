/** Player.h
 *	
 *	A Player.h file that represents a player in BlackJack.   
 *
 *   
 *	@author		P. Massardo
 *	@version	2014.01
 *  @description The player class is the main access and control between between the game (BlackJackFinal.cpp) 
 				and the hand itself. The player can have a number of hands with this game the most the player 
				can have is two, but an array was used to enable the possibility of more. 
				
 *	@since		December 2014
*/



#ifndef _STD_PLAYER
#define _STD_PLAYER

#include <iostream>
#include "Hand.h"
#include "Dealer.h"
#include "ChipBank.h"
#include <math.h> 
#include <map>
#include "MyInputValidation14.h"

using namespace std;

class Player 
{	
	public:
	
		string GetName() const { return myName;};
		
		/* 
			Split 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	based on the handIndex this function will take the given hand
							and split it assigning the two existing cards to the two new decks								
			@param			Dealer - current dealer object
			@param			int - index of the hand to split
			@return			void
		*/		
		void Split(Dealer *dealer,int handIndex);
		
		/* 
			Hit 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	assigns a new card to an existing hand								
			@param			Dealer - current dealer object
			@param			int - index of the hand to hit
			@param			bool - show message
			@return			void
		*/
		void Hit(Dealer *dealer, int handIndex, bool withMessage) ;
		
		/* 
			Stand 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	currently does nothing								
			@param			NA
			@return			void
		*/
		void Stand(int handIndex);
		
		/* 
			DoubleDown 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	sets a hand to stand								
			@param			int - index of the hand to stand
			@return			void
		*/
		void DoubleDown(Dealer* dealer,int handIndex);
		
		/* 
			Surrender 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	will take the existing bet and reduce the chips base on the 50% of the original bet								
			@param			int - index of the hand to surrender
			@return			void
		*/
		void Surrender(int handIndex); 
		
		/* 
			UpdateChipBalance 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	will take the existing bet and reduce the chips base on the 50% of the original bet								
			@param			int - amount to added or subtract from the chip balance after a win or a loss
			@param			bool - true if it is a win so the amount to be added false if it is a loss so the amount to be subtracted from the chips
			@return			int - returns the new chip balance
		*/		
		int UpdateChipBalance(int amountInWholeDollars, bool isAdd); 
		
		/* 
			Bet 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	will set assign an amount the player committs to if a loss and how much they get if they win								
			@param			int - amount that the player commits to give up if the players loses or the amount they will add if they win
			@param			int - index of the hand to assign the bet to
			@return			void
		*/	
		void Bet(int handIndex);
		
		/* 
			GetBet 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	gets the bet for a given hand								
			@param			int - index of the hand to get the bet
			@return			int - returns the amount of a bet
		*/	
		int GetBet(int handIndex) const;
		

		/* 
			GetHandValue 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	gets the value of a specified hand								
			@param			int - index of the hand to assign the bet
			@return			int - returns the value of the hand returns the value that is visible,
								 so the same function in dealer only show the visble amount
		*/		
	 	int GetHandValue(int =0) const;

		/* 
			GetNumberOfHands 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	gets the value of a specified hand								
			@param			NA
			@return			int - returns the number of hands the player is holding
		*/	 	
		int GetNumberOfHands() const  {return myNumberOfHands;};

	 	/* 
			DisplayHand - 	function 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	shows the hand based on the given index			
			@param			int - index of the hand 
			@return			string - the representation to of the hand
		*/	 	
	 	string DisplayHand(int handIndex) const; 
	 	
	 	/* 
			SetName - 	function 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	sets the name			
			@param			string - the name to be set 
			@return			NA
		*/	 	
	 	void SetName(string name){myName = name;}; 
	 	
	 	/* 
			DisplayPlayer - 	constructor 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	shows the hand based on the given index			
			@param			NA 
			@return			string - the representation to of the playrer
		*/	 	
	 	string DisplayPlayer(); 
	 	
		 /* 
			GetHandIntelligence - 	function 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	return a char telling the player what to do	for a particular hand		
			@param			index - hand index 
			@return			char - the representation of what the player should do
		*/	 	
	 	char GetHandIntelligence(int indexHand, int dealerHandValue); 
	 	
	 	/* 
			Player - 	constructor 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	Constructor for the CardShoe			
			@param			int - number of hands
			@param			bool - is the player a human
			@param			bool - is the player in a loss position			
			@return			NA
		*/
		Player(int numberOfHands = 1, bool isHuman=false, bool isLoss=false);
		
		/* 
			FlipIsHuman - 	function 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	If the paly is not a human it will be set to human			
			@return			NA
		*/
		void FlipIsHuman() { (myIsHuman==false)?myIsHuman=true:myIsHuman=false;};
		
		/* 
			GetIsHuman - 	function 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	If the paly is not a human it will be set to human			
			@return			NA
		*/
		bool GetIsHuman() { return myIsHuman;};
		
		/* 
			GetIsLoss - 	function 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	If the paly is not a human it will be set to human			
			@return			bool - is the player is out of cash
		*/
		bool GetIsLoss() { return myIsLoss;};
		
				/* 
			ClearBet - 	function 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	clears bet for a given hand
			@param			index - hand index 			
			@return			NA
		*/
		void ClearBet(int handIndex); 

		/* 
			ResetHand - 	function 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	sets the players hand back to one empty hand
			@return			NA
		*/		
		void ResetHand();
		
		/* 
			GetIsHandBust - 	function 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	is the current hand a bust
			@param			int - index of the given hand			
			@return			bool - is the current hand a bust
		*/
		bool GetIsHandBust(int handIndex);
		
		/* 
			GetIsHandOkToPlay - 	function 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	is the given hand okay
			@param			int - index of the given hand			
			@return			bool - is the current hand is okay to play
		*/ 	
 		bool GetIsHandOkToPlay(int handIndex);
 		
		/* 
			GetHandKey - 	function 
			@author 		P. Massardo
			@since			31-Oct-2014
			@description	gets the hand key from the given hand
			@param			int - index of the given hand			
			@return			string - keyvalue
		*/ 	 		
		string GetHandKey(int handIndex, int dealerHandValue); 		
 	
 	private:
 		
	 	// class level private variables
		Hand * myHands; 
		ChipBank chipBank;
		string myName;
		int myNumberOfHands;
		bool myIsHuman;
		bool myIsLoss;
		bool myIsDone;
		
};

	// constant use for hand names in the event of a split (first and second are the only ones really used, I just like the completeness of 10)
	const string HAND_NAME[10] = { "First", "Second", "Third", "Fourth", "Fifth", "Sixth", "Seventh" , "Eigth" , "Nineth" , "Tenth" };

Player::Player(int numberOfHands, bool isHuman, bool isLoss)
{

	myNumberOfHands = numberOfHands;
	myHands = new Hand[numberOfHands];
	myIsHuman=isHuman;
	myIsLoss=isLoss;

}

void Player::ResetHand()
{
	
	delete  [] myHands;
	myNumberOfHands = 1;
	myHands = new Hand[myNumberOfHands];
	
}
int Player::GetHandValue(int handIndex) const
{

	int returnValue;
	int softValue = myHands[handIndex].Value(true,false);
	int hardValue = myHands[handIndex].Value(true,true) ;
	
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

int Player::GetBet(int handIndex) const
{

	return myHands[handIndex].GetBet();

}

bool Player::GetIsHandBust(int handIndex)
{

	return myHands[handIndex].GetIsBust();

}

bool Player::GetIsHandOkToPlay(int handIndex)
{

	return myHands[handIndex].GetIsHandOkToPlay();

}

void Player::ClearBet(int handIndex)
{
	
	myHands[handIndex].PlaceBet(0);
}

string Player::GetHandKey(int handIndex, int dealerHandValue)
{
	
	return myHands[handIndex].GetHandKey(dealerHandValue);
	
}

string Player::DisplayHand(int handIndex) const
{
	
	// declare a stringstream object
	stringstream strOut; 

	strOut << "\n-------------------" << endl;
	strOut << myName << "'s " << HAND_NAME[handIndex] << " Hand" << endl;
	strOut << myHands[handIndex].DisplayHand();
	strOut << "Hand soft value showing " << myHands[handIndex].Value(false,false) << endl;
	strOut << "Hand hard value showing " << myHands[handIndex].Value(false,true) << endl;
	strOut << "Hand bet is " << myHands[handIndex].GetBet() << endl;
	//strOut << "Is Allowed Surrender " << myHands[handIndex].GetIsAllowedToSurrender()<< endl;
	strOut << "-------------------" << endl;
	
	return  strOut.str();
	
}

string Player::DisplayPlayer() 
{
	
	// declare a stringstream object
	stringstream strOut; 

	strOut << "\n-------------------" << endl;
	strOut << myName << "'s Chip balance is $" << chipBank.getBalance() << endl;
	for(int handIndex =0; handIndex< myNumberOfHands ; handIndex++)
	{
		
		strOut << myHands[handIndex].DisplayHand();
		strOut << "Hand soft value showing " << myHands[handIndex].Value(false,false) << endl;
		strOut << "Hand hard value showing " << myHands[handIndex].Value(false,true) << endl;
		strOut << "Hand bet is " << myHands[handIndex].GetBet() << endl;
		//strOut << "Hand Key " << myHands[handIndex].GetHandKey(2) << endl;
		//strOut << "Is Allowed Surrender " << myHands[handIndex].GetIsAllowedToSurrender()<< endl;
		
	}
	
	strOut << "-------------------";
	
	return  strOut.str();
	
}

void Player::Split(Dealer *dealer,int handIndex) 
{
	
	// notes for Swity all the split does is split
	// it does not validate if the two cards are eligible
	// to split. Eligibility will come from the check of the
	// intelligence. 
	
	cout << endl << myName << " has chosen to split. " << endl;
	
	// Also it is possible that the split hand could be a pair
	// of matching values as well, so it should be checked again
	// with the intelligence class	
	
	Hand newHandOne;
	Hand newHandTwo;  
	StandardPlayingCard card;
	int bet=0;
	int firstCardValue=0;
	bool okayToSplit = true;
	
	
	Hand *myTempHands = new Hand[myNumberOfHands+1];
	
	// loop the decks 
	for(int index = 0; index< myNumberOfHands;index++)
	{
		// if it is not the hand to split
		if(index!=handIndex)
		{
			// then add it to the temporary deck
			myTempHands[index] = myHands[index];
		}
		else
		{
			// if it is the hand to split create a a new hand and get
			// the first card from the deck which should be the same as the 
			// second card which is why we are splitting

			// new hand one get the first card
			// from te old hand and give it to 
			// newly created hand
			card = myHands[index].GetCard(0);
			firstCardValue = card.getRankValue();
			newHandOne.Hit(card);
			
			// get a new card from the dealer
			// and give it to the new hand
			card = (*dealer).DrawNextCard();
			newHandOne.Hit(card);
			
			// get the old bet and pass it
			// to the new hand
			bet = myHands[index].GetBet();			
			newHandOne.PlaceBet(bet);

			// new hand two get the second card
			// from the old hand and give it to 
			// newly created hand
			card = myHands[index].GetCard(1);
			
			// check to see if the cards the 
			// player is attempting to split
			// are of the same value 
			if(firstCardValue != card.getRankValue())
			{
			
				// inform the user that they cannot split	
				cout << endl << myName << " split can only occur between two cards of the same value. " << endl;
				
				// set okay to split to false
				okayToSplit=false;
				
				// release the temp memory of the class level array
				delete  [] myTempHands;
				
			}
			else
			{
				// it is a valid split
			
				newHandTwo.Hit(card);
	
				// get a new card from the dealer
				// and give it to the new hand						
				card = (*dealer).DrawNextCard();
				newHandTwo.Hit(card);
				
				// pass the old bet to the new 
				// second hand			
				newHandTwo.PlaceBet(bet);			
	
				// add the new hadn to the
				// hands array 
				myTempHands[index] = newHandOne;
				myTempHands[index+1] = newHandTwo;
				
			}
			
		}
		
	}
	
	// only delete memory and increment
	// the number of hands if it is okay
	// to split
	if(okayToSplit==true)
	{		
		
		// release the memory of the class level array
		delete  [] myHands;
		
		myNumberOfHands++;
		
		// set the class level array to the temp array
		myHands = myTempHands;
		
	}
		
}
void Player::Hit(Dealer* dealer, int handIndex, bool withMessage) 
{

	if(withMessage) 
	{
		
		cout << endl << myName << " has chosen to hit. " << endl;
	
	}
		
	// get the next card and pass it to the hand
	StandardPlayingCard newCard = (*dealer).DrawNextCard(); 
	
	// add the card to the hand
	myHands[handIndex].Hit(newCard);
	
}

void Player::Stand(int handIndex) 
{
	
	// do nothing
	// it is a stand I'm only puuting this in now for completeness in development
	// maybe display message
	cout << endl << " has chosen to stand. " << endl;
	
	// since they've chosen to stand this hand is no longer
	// to be used in the game 
	myHands[handIndex].SetIsHandOkToPlay(false);

	
}

// will reduce the number of chips when it is done
void Player::Surrender(int handIndex) 
{

	// declare and initialize the offset
	int offSet = 0;
	int bet=0;
	
	if(!(myHands[handIndex].GetIsAllowedToSurrender()))
	{
		
		cout << myName << " you are not allowed to surrender after the initial two cards are dealt! " << endl;
		
	}
	else
	{
	
		// stop playing this hand but only loose half your bet
		// this can only be done after the first two cards of
		// the original hand are dealt.
		// after anything else happens (split, hit (get a third card), doubledown) 
		// you are no longer allowed to surrender
				
		cout << endl << " has chosen to surrender. " << endl;
		
		bet = (myHands[handIndex].GetBet()*.50);
		
		// get the bet on the hand
		if(bet< 10)
		{
			
			bet = 10;			
			
		}
		else if((bet%10) !=0)
		{
			bet = ceil((double(bet)/10))*10;
		}
		
		Hand *myTempHands;
		
		// reduce the chip balance
		UpdateChipBalance(bet, false); 
		
		// the surrender will also need to release the players
		// create a temp array
		
		if(myNumberOfHands>1)
		{
		
			 myTempHands = new Hand[myNumberOfHands-1];
			
			// iterate through the current array
			for(int index = 0; index < myNumberOfHands-1; index++)
			{
				// add the old array data except 
				// for the element at the cardToRemoveIndex
				if(handIndex==index)
				{
		
					// set the offset
					offSet=1;	
				
				}
				
				// set the element in the temp array
				myTempHands[index] = myHands[index+offSet];
				
			}
			
			// lower the size variable by one	
			myNumberOfHands--;
			
		}
		else
		{
			// if this is the only hand reset the number of hands to 1
			myNumberOfHands=1;
			
			// set the temp to a new empty hand
			myTempHands = new Hand[myNumberOfHands];
		}
		
		// release the memory of the class level array
		delete  [] myHands;
		
		// set the class level array to the temp array
		myHands = myTempHands;
	
	}
	
	// since they've surrendered this hand is no longer
	// to be used in the game
	myHands[handIndex].SetIsHandOkToPlay(false);
	
}

// will reduce the number of chips when it is done
int Player::UpdateChipBalance(int amountInWholeDollars, bool isAdd) 
{
	
	// stop playing this hand but only loose half your bet
	// this can only be done after the first two cards of
	// the original hand are dealt.
	// after anything else happens (split, hit (get a third card), doubledown) 
	// you are no longer allowed to surrender
	
	int newBalance = 0;
	
	// if we are adding (we are upadting because we have won)
	// get the old balance and add the winnings to the chipbank	
	if(isAdd)
	{
		newBalance = chipBank.getBalance() + amountInWholeDollars;
	}
	else
	{

		
		// subtract the amount passed in from the current balance 
		newBalance = chipBank.getBalance() - amountInWholeDollars;
		
		// if the amount in passed is more tha the
		// current balance then the player has lost
		if(newBalance <= 0)
		{
			
			// set the loss to true
			myIsLoss=true;
			
		}
		
		
	}
	
	// set the new amount in the chip bank
	chipBank.setBalance(newBalance);
	
	return newBalance;
	
}

void Player::Bet(int handIndex)
{
	
	// declare a stringstream object
	stringstream strOut;

	bool betAmountIsNotOk = false;
	int bet= 10;
	
	const int MIN_BET = 10;
	
	int bankBalance = chipBank.getBalance();
	
	if (myIsHuman==true)
	{
	
		strOut << myName << " how much would you like to bet? ";
	
		// valid that the correct chip purchase is being made
		do
		{		
	
			bet = myValidation14::GetValidInt(strOut.str());
			
			// validate the number of decks
			if ((bet< MIN_BET) or (bet%MIN_BET!=0) or (bet>bankBalance))
			{
				cout << "\nBets need to be in increments of " << MIN_BET << " and you bet must be no more than the value of your chips!" << endl;
				betAmountIsNotOk=true;
			}
			else
			{
				// pass the name to the object
				betAmountIsNotOk = false;
			}	
		
		}while(betAmountIsNotOk==true);
	
	}
	
	myHands[handIndex].PlaceBet(bet);
	
}

void Player::DoubleDown(Dealer* dealer,int handIndex)
{
	// The player is allowed to increase the initial bet by up to 100% 
	// in exchange for committing to stand after receiving exactly one more card.
	// so once a double down happens the player can only ask for one more card
	
	cout << endl << myName << " has chosen to double down. " << endl;
	
	// declare a stringstream object
	stringstream strOut; 
	
	char hit;
	
	int bet = myHands[handIndex].GetBet();
	
	if (myIsHuman==true)
	{
	
		strOut << myName << " how much would you like to bet? ";
		
		bet = myValidation14::GetValidInt(strOut.str());
		
		cout << "\n" << myName << " Double down allows for one more hit, would you like to hit? ('Y' or 'N') ";
		cin >> hit;
		
		if((hit=='Y') or (hit=='y'))
		{
			Hit(dealer, handIndex, true); 
		}
		
	}
	else
	{ // computer player
		
		// will hit
		Hit(dealer, handIndex, true); 
		
	}
	
	myHands[handIndex].DoubleDown(bet);
	myHands[handIndex].SetIsHandOkToPlay(false);

	
}

//char Player::GetHandIntelligence(int indexHand, int dealerHandValue)
//{
//		
//	char returnValue ='S';
//	
//	string keyValue = myHands[indexHand].GetHandKey(dealerHandValue);
//		
//	
//		
//		
//		
//	//Hand hand = myHands[indexHand];
//
//	// Marisol's code goes here passing in the keyValue to get
//	// the response from intelligence
//
//	//returnValue = testIntelligenceSuggestion(hand);
//
//	//LogGame("GAME LOG ::: GetHandIntelligence = " + returnValue);
//
//	return returnValue;	
//} 




#endif

