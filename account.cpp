#include <iostream>
#include <string>
#include "account.h"
using namespace std;

//Default Constructor
account::account()
{
	balance = new double(0.00);
		
}

//Parameterized constructor
account::account(double _balance)
{
		
	if(balance < 0)
	{
		balance = new double(0.00);
		cout << "Your balance is less than $0.00!" << endl;
	}
	else
	{
		balance = new double(_balance);
	}
	
}

//Destructor
account::~account()
{
	delete balance;
	
}

//Mutator
void account::setBalance(double _balance)
{
	balance = new double(_balance);
}

//Accesstor

double account::getBalance()
{
	
	return *balance;
	
}

//Debit
void account::debit(double amount)
{
	if(amount > getBalance())
	{
		cout << "Debit amount exceeded account balance!" << endl;
	}
	else
	{
		setBalance(getBalance() - amount);
	}
	
}

//Credit
void account::credit(double amount)
{
	setBalance(getBalance() + amount);
	
}

