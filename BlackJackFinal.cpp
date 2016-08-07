/** BlackJackFinal.cpp
 *	
 *	A cpp that controls the entire game of BlackJack.   
 *
 *   
 *	@author		P. Massardo
 *	@version	2014.01
 *  @description This cpp file is the user interface and the main control of the BlackJackFinal program.
 			     It has been design to ask the user for the number of decks to be played by the dealer,
				 as well as, the number of human and computer players. Once decided it asks each of the human 
				 players the dollar value of the chips to be purchased. Computer/Intelligence controlled players
				 are defaulted to $500 in chips and $10 bets. Computer controlled player's plays are controlled
				 by the Intelliigence class which loads a file into a map/char container and based on a key value
				 created by the hand object/container returns a key which is used to determine the current play. The human
				 player is given a suggestion based on their hand, but they can choose to do what ever they want 
				 at their own PERIL!!!! (I would do the scary Halloween laugh now, but I'm by myself and that 
				 would seem dumb.) Hope this line gives someone a chuckle.
				   			     
 *	@since		December 2014
*/


#include <iostream>
#include "Player.h"
#include "Players.h"
#include "MyInputValidation14.h"
#include "Dealer.h"
#include "Hand.h" 
#include "Intelligence.h"

using namespace std;

using namespace myValidation14;

char IntelligenceSuggestion(Hand& hand);

void Introduction(Dealer *dealer,Players *players, int numberOfHumanPlayers, int numberOfComputerPlayers);

void PlayersInitialBet(Players *players);

void CurrentState(Dealer *dealer, Players *players);

int main()
{

	const int INITIAL_DEAL = 2;
	int bet = 0; 	
	bool pleaseStopInividualPlaysOnThisHand = false;
	bool showCard=false;
	bool continueGamePlay=true;
	bool isHandABust = false;
	bool isDealerHandABust = false;
	bool isOkayToContinue = true;

	string answer="";	
	int numberOfHands=0;
	int dealerHandValue=0;
	int playerHandValue=0;
	char intelligenceSuggestion;
	int playerHandLossCount =0;
	int dealerHandLossCount =0;
	bool deckIsNotOk = true;
	const int MIN_DECKS = 2;
	const int MAX_DECKS = 8;
	int numberOfDecks;
	Intelligence intel;
	
	
	// valid date the the number of decks user input
	do
	{
		
		// get the number of decks	
		numberOfDecks = GetValidInt("How many decks would you like to play with? ");
		
		// validate the number of decks
		if ((numberOfDecks< MIN_DECKS) or (numberOfDecks> MAX_DECKS) or (numberOfDecks%2!=0))
		{
			cout << "Decks need to be 2, 4, 6, or 8" << endl;
		}
		else
		{
			deckIsNotOk = false;
		}	
	
	}while(deckIsNotOk==true);
	
	
	int numberOfHumanPlayers = GetValidInt("How many human players would you like to play with? ");
	int numberOfComputerPlayers = GetValidInt("How many computer players would you like to play with? ");
	int numberOfPlayers = numberOfHumanPlayers+numberOfComputerPlayers;
	int numberOfRemainingHands = numberOfHumanPlayers+numberOfComputerPlayers;
	intel.LoadIntelligence("strategyfile.txt");
	
	// create a dealer	
	Dealer *dealer = new Dealer(numberOfDecks);
	Players *players = new Players(numberOfPlayers);
	StandardPlayingCard card; 
		
	Introduction(dealer,players, numberOfHumanPlayers, numberOfComputerPlayers);

	//CurrentState(dealer,players);
	
	// shuffle cards
	(*dealer).Shuffle();
	
	// each player plays until they stop or their chipbank is empty
	
	bool isLoss ;

	do
	{
		
		cout << " ------------------ Start hand ----------------- " << endl;
		
		// initial bet
		for(int indexPlayers=0; indexPlayers<numberOfPlayers;indexPlayers++)
		{
			
			// is a player has already lost (no chips)
			// then there is not much point
			// in asking them to play			
			isLoss = (*players)[indexPlayers].GetIsLoss();
			
			if(isLoss==false)
			{
			
				numberOfHands = (*players)[indexPlayers].GetNumberOfHands();
				
				for(int indexHand=0; indexHand<numberOfHands;indexHand++)
				{
					
					// ask the players for a bet
					// human players will be asked
					// computer players are automated
					(*players)[indexPlayers].Bet(indexHand);
				
				}
				
			}
			
		}
		
		//CurrentState(dealer,players);
		
		// initial deal
		
		for(int indexCards=0; indexCards<INITIAL_DEAL;indexCards++)
		{
				
			// deal cards	
			for(int indexPlayers=0; indexPlayers<numberOfPlayers;indexPlayers++)
			{
				
				// is a player has already lost (no chips) then 
				// there is not much point in dealing to them			
				isLoss = (*players)[indexPlayers].GetIsLoss();
				
				if(isLoss==false)
				{
				
					numberOfHands = (*players)[indexPlayers].GetNumberOfHands();
					
					for(int indexHand=0; indexHand<numberOfHands;indexHand++)
					{
						// this is just the deal not an actual hit
						// so supress the hit message (false)
						(*players)[indexPlayers].Hit(dealer,indexHand, false);
						
					}
					
				}
				
			}
			
			// if it is the first card in 
			// the dealers hand do not show it
			if (indexCards==0)
			{
				(*dealer).Hit(true);			
			}
			else
			{
				(*dealer).Hit(false);
			}
		
		}
		
		CurrentState(dealer,players);
		
		// player interaction
		for(int indexPlayers=0; indexPlayers<numberOfPlayers;indexPlayers++)
		{
			
			// is a player has already lost (no chips) then 
			// there is not much point in dealing to them			
			if((*players)[indexPlayers].GetIsLoss()==false)
			{
			
				numberOfHands = (*players)[indexPlayers].GetNumberOfHands();
				
				for(int indexHand=0; indexHand<numberOfHands;indexHand++)
				{
					
					// keep asking the player what they want to do until they 
					// ---bust, 
					// ---want to stop, (stand)
					// --- or need to stop (they've hit after a double down, or they've already surrendered)  
					do 
					{
						// get the intelligence suggested play
						intelligenceSuggestion = intel.GetIntelligence((*players)[indexPlayers].GetHandKey(indexHand, (*dealer).GetHandValue()));  // (*players)[indexPlayers].GetHandIntelligence(indexHand, (*dealer).GetHandValue());
						
						//cout << "test key - " << (*players)[indexPlayers].GetHandKey(indexHand, (*dealer).GetHandValue()) << endl;
						
						// display the hand to the user
						cout <<	 (*players)[indexPlayers].DisplayHand(indexHand);					
				 
						if(intelligenceSuggestion=='H')
						{
							cout<< "\nStrategy suggests you should Hit (H or h) ..." << endl;
						}
						else if(intelligenceSuggestion=='S' || intelligenceSuggestion=='P')
						{
							cout<< "\nStrategy suggests you should Split (S or s) ..." << endl;
						}
						else if(intelligenceSuggestion=='D')
						{
							cout<< "\nStrategy suggests you should Double Down (D or d) ..." << endl;
						}
						else if(intelligenceSuggestion=='U')
						{
							cout<< "\nStrategy suggests you should Surrender (U or u) ..." << endl;
						}
						else if(intelligenceSuggestion=='N')
						{
							cout<< "\nStrategy suggests you should Stand (N or n) ..." << endl;	
						}
						
						cout<< "\nWould you like to ..." << endl
							<< "........ Hit? (H or h)" << endl
							<< "........ Split (S or s)" << endl
							<< "........ Surrender? (U or u)" << endl
							<< "........ Double Down? (D or d)" << endl
							<< "........ Stand? (N or n) ...";
						
						// if it is the human player
						if((*players)[indexPlayers].GetIsHuman()==true)
						{
								
							// get the human player response
							// computer player will just go with 
							// the intelligence suggestion
							cin>>intelligenceSuggestion;
							cin.ignore();
								
						}
						
						if((intelligenceSuggestion=='H') or (intelligenceSuggestion=='h'))
						{
		
							(*players)[indexPlayers].Hit(dealer,indexHand,true);
		
						}
						else if(((intelligenceSuggestion=='S') or (intelligenceSuggestion=='s')) or 
								((intelligenceSuggestion=='P') or (intelligenceSuggestion=='p')))  
						{
							
							(*players)[indexPlayers].Split(dealer,indexHand);
							numberOfHands = (*players)[indexPlayers].GetNumberOfHands(); 
							
						}
						else if((intelligenceSuggestion=='U') or (intelligenceSuggestion=='u'))
						{
							
							(*players)[indexPlayers].Surrender(indexHand);
							numberOfHands = (*players)[indexPlayers].GetNumberOfHands();
							playerHandLossCount++;
						
						}
						else if((intelligenceSuggestion=='D') or (intelligenceSuggestion=='d'))
						{
							
							(*players)[indexPlayers].DoubleDown(dealer,indexHand);
							
						}					
						else if((intelligenceSuggestion=='N') or (intelligenceSuggestion=='n'))
						{
							// anything else will stop play
							(*players)[indexPlayers].Stand(indexHand);
							
						}	

						// check if the hand is a bust
						// bust is set on the hit when a new card is drawn
						// in the hand itself
						cout <<	(*players)[indexPlayers].DisplayHand(indexHand) << endl;
						
						
						if((*players)[indexPlayers].GetIsHandBust(indexHand)==true)
						{

							// tell the player their hand was a bust
							cout << "This hand is bust!!!" << endl;
							
							// update the chip balance as if it is a loss
							(*players)[indexPlayers].UpdateChipBalance((*players)[indexPlayers].GetBet(indexHand),false);
							
							// set the bet to 0 for this particular hand
							// as the player may have another hand in play
							(*players)[indexPlayers].ClearBet(indexHand);
							
						}
											
						
					}while((*players)[indexPlayers].GetIsHandOkToPlay(indexHand)==true);
				
				}
				
			}
			
		}
		
		(*dealer).FaceUpAllCards();
		
		// dealers shows current cards before getting more
		CurrentState(dealer,players);
		
		// check to see if there any active hands
		// if all the hands are but then the dealer does not need to proceed
		// with drawing cards.
		if((*players).GetActiveHandCount()>0)
		{
		
			//
			do
			{
				// check to see if the dealer is allowed 
				// to hit with the dealer's current hand of cards
				if((*dealer).OkToHit())
				{
					
					// dealer takes a card
					// that will not be hidden		
					(*dealer).Hit(false);
				
				}
				else
				{
					// end the loop
					isOkayToContinue = false;
				}
				
			}while(((*dealer).GetIsHandBust()==false) and ((*dealer).OkToHit()==true));
			
			// dealers shows current cards before determination 
			// of win or loss
			CurrentState(dealer,players);		
			
			dealerHandValue = (*dealer).GetHandValue();
			isDealerHandABust = (*dealer).GetIsHandBust();
			
			// compare the dealers hand to all the players hands
			// players hands who are bust will not be compared even if the dealer's hand is a bust
			// ,as well, players who are in an loss (no chips) will not be compared because they 
			// will not be in play
			// only players who have a hand that is not over 21 will be compared
			for(int indexPlayers=0; indexPlayers<numberOfPlayers;indexPlayers++)
			{
				
				// is a player has already lost (no chips) then 
				// there is not much point in comapring their hand
				// to the dealer			
				if((*players)[indexPlayers].GetIsLoss()==false)
				{
				
					numberOfHands = (*players)[indexPlayers].GetNumberOfHands();
					
					for(int indexHand=0; indexHand<numberOfHands;indexHand++)
					{
						
						isHandABust= (*players)[indexPlayers].GetIsHandBust(indexHand);
						
						if(isHandABust!=true)
						{
							
							playerHandValue = (*players)[indexPlayers].GetHandValue(indexHand);
							
							if((playerHandValue>dealerHandValue) or (isDealerHandABust==true))
							{
								
								// players who beat the dealer will be paid their bet and it is added to their 
								// chip count and they will cheer and do shaving commercials 
								// (we do not discriminate face or legs)
								
								// update the chip balance as if it is a loss
								(*players)[indexPlayers].UpdateChipBalance((*players)[indexPlayers].GetBet(indexHand),true);
								
								
							}
							else if((playerHandValue<dealerHandValue) and (isDealerHandABust==false))
							{
								
								// players who are lower than the dealer lose their bets and it is 
								// subtracted from their chip count and they should also cry, just a little
								(*players)[indexPlayers].UpdateChipBalance((*players)[indexPlayers].GetBet(indexHand),false);
	
								
							}
							else
							{
	
	
								// players who tie the dealer will not paid nor have their bets taken the 
								// bet will be cleared, and everyone will be indifferent, maybe a little sad
	
								
							}
	
							// set the bet to 0
							(*players)[indexPlayers].ClearBet(indexHand);
						
						}
			
					}
				
				}
				
			}
		
		}
		else
		{
			
			cout<< "\nAll player hands were a bust! Dealer draws no cards"<< endl;
			
		}
		
		CurrentState(dealer,players);	
		
		if((*players).GetActivePlayerCount()==0)
		{
			
			continueGamePlay=false;
			
		}
		
		// need to reset hands
		(*players).ResetPlayersHands();
		(*dealer).ResetHand();
		
		cout << " ------------------ end hand ----------------- " << endl;
		
	}while(continueGamePlay==true);
	

}

void Introduction(Dealer *dealer, Players *players, int numberOfHumanPlayers, int numberOfComputerPlayers)
{

	string name;
	int chipAmount=0;
	stringstream strOut; 
	int numberOfPlayers = (*players).GetPlayerCount();
	int totalNumberOfPlayers = numberOfHumanPlayers+ numberOfComputerPlayers;
	bool chipAmountIsNotOk = true;
	const int MIN_CHIPS = 10;
	const int COMPUTER_PLAYER_BUY_CHIPS = 500;
		
	// names and purchase chips	
	for(int indexPlayers=0; indexPlayers<totalNumberOfPlayers;indexPlayers++)
	{

		// clear the string stream		 
		strOut.str(std::string());

		
		// first number of players will always be the human
		if(indexPlayers<numberOfHumanPlayers)
		{
			
			(*players)[indexPlayers].FlipIsHuman();
			
			// for the human ask for a name
			cout << "Hello what is your name? ";
			
			// get the response
			cin>> name;
			
			// pass the name to the object
			(*players)[indexPlayers].SetName(name);
			
			// valid that the correct chip purchase is being made
			do
			{
				
				// for the human ask for a chip puchase amount
				strOut << name << " what dollar amount would you like to purchase in chips? ";
				
				// get the chip amount
				chipAmount=GetValidInt(strOut.str());
				
				// validate the number of decks
				if ((chipAmount< MIN_CHIPS) or (chipAmount%MIN_CHIPS!=0))
				{
					cout << "Chips need to be purchased in increments of " << MIN_CHIPS << endl;
					chipAmountIsNotOk=true;
				}
				else
				{
					// pass the name to the object
					(*players)[indexPlayers].UpdateChipBalance(chipAmount, true);
					chipAmountIsNotOk = false;
				}	
			
			}while(chipAmountIsNotOk==true);
			
		}
		else
		{
			
			// for the computer players assign index count plus 1			
			strOut << (indexPlayers+1);
			
			// pass the name to the object
			(*players)[indexPlayers].SetName(strOut.str());
		
			// for the computer players assign 500 dollars 
	
			// pass the name to the object
			(*players)[indexPlayers].UpdateChipBalance(COMPUTER_PLAYER_BUY_CHIPS, true);
						
		}

	}
	
	CurrentState(dealer, players);
	
}

void CurrentState(Dealer *dealer, Players *players)
{
	
	int numberOfPlayers = (*players).GetPlayerCount();
	char response;
	
	cout << "\n---------Current Status----------" << endl;
	
	cout << (*dealer).DisplayHand() << endl;
	
	// names and purchase chips	
	for(int indexPlayers=0; indexPlayers<numberOfPlayers;indexPlayers++)
	{
	
		cout << (*players)[indexPlayers].DisplayPlayer()<< endl;
	
	}
	
	cout << "\n---------------------------------" << endl;
	cout << "\nPress any key and enter to continue playing..." << endl;
	cin >> response;
	cin.ignore();	
	
}



