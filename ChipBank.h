/** ChipBank.h
 *	
 *	In this file, we declare and define the ChipBank class.  It is a very simple class that has only a few
 *  methods.  Table rules indicate the all bets are in multiples of $10 and that the minimum bet is $10.
 *  The maximum bet is $100 at this table.
 *  
 *	@author		C. Foster
 *	@modifications P. Massardo
 *	@version	2014.01
 *	@since		Nov 2014
 */

#ifndef _CHIPBANK
#define	_CHIPBANK

#include <iostream>
#include <sstream>		// for stringstream
//#include <cmath>		// for sqrt()

using namespace std;

// class declaration section
class ChipBank
{
  public:
  	/* Constructor: Used to initialize objects
	 *	- always the same name as the class
	 *	- never has a return type
	 *	- called automatically when an obj is instantiated
	 *	- should set values for each member variable
	 */
	//ChipBank(); 
	ChipBank(int value = 0, int balance = 0) : myValue(value), myBalance(balance) {}
	 
	/* Accessors: Used to query the state of the object
	 *	- never modifies the object
	 *	- should specify const at the end of the prototype/header
	 */    
	int getValue() const {return myValue;}
	int getBalance() const { return myBalance;}
		
	/* Mutator(s): Used to change the state of the object
	*	- should contain logic to ensure object remains in a valid state.
	*	- typically sets a member variable to a parameter
	*/
	void setValue(int x) { myValue = x; }
	void setBalance(int x) { myBalance = x; }
	
	// class function Initialize
	int Initialize(void);
	// return value is the amount in the bank (usually $1000)
	
	// class function BuyChips
	int SellChips(int value);
	// value is the amount of chips that the player wants to buy
	// returns value purchased
	
	// class function TakeWinnings
	void TakeWinnings(int value);
	// value is the winnings amount that the dealer takes off the table
	
	// class function CashInChips - this is a cashier function
	int CashInChips(int value);
	
  private: 
    int myValue; 
	int myBalance; // chip bank balance
           
};

	// class function Initialize
	int ChipBank::Initialize(void)
	{
		// return value is the amount in the bank (usually $1000)
		int INITIAL_BANK_BALANCE = 1000;
		setBalance(INITIAL_BANK_BALANCE);
		return getBalance();
	}
	
	// class function BuyChips
	int ChipBank::SellChips(int value)
	{
		int returnValue = 0;
		int newBalance = 0;
		int theBalance = 0;
		
		// reduce the chip bank balance
		theBalance = getBalance();
		
		if (theBalance >= value)
		{
			// go ahead and reduce the bank balance
			newBalance = theBalance - value;
			returnValue = newBalance;	
		}
		else
		{
			// pick up another bank of chips and try again
			Initialize();
			theBalance = getBalance();
			newBalance = theBalance - value;
			returnValue = newBalance;	
		}
		
		setBalance(newBalance);
		return returnValue;
	}
	
	int ChipBank::CashInChips(int value)
	{
		// this function is called when the player is finished at the table
		int returnValue = 0;
		int theBalance = 0;
		int newBalance = 0;
		
		theBalance = getBalance();
		
		if (value >= theBalance)
		{
			Initialize();
			newBalance = getBalance() - value;
			setBalance(newBalance);
		}
		else
		{
			newBalance = getBalance() - value;
			setBalance(newBalance);
		}
	}
	
	// class function TakeWinnings
	void ChipBank::TakeWinnings(int value)
	{
		int theBalance = 0;
		theBalance = getBalance() + value;
		setBalance(theBalance);
		
	}

#endif
