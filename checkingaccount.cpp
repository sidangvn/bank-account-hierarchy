#include <iostream>
#include <string>
#include <iomanip>
#include "account.h"
#include "savingsaccount.h"
#include "checkingaccount.h"
using namespace std;

//Default constructor
checkingaccount::checkingaccount()
{
	feeForTransaction = new double(0.00);
}

//Parameterized Constructor
checkingaccount::checkingaccount(double balance, double _feeForTransaction)

	:account(balance)
	{
	
		if(_feeForTransaction < 0.00)
		{
			feeForTransaction = new double(0.00);
			cout << "Error! fee for transaction can't be negative!" << endl;
		}
	
		else
		{
			feeForTransaction = new double(_feeForTransaction);
		}
	
	}


//Destructor
checkingaccount::~checkingaccount()
{
	delete feeForTransaction;
}

//Debit
void checkingaccount::debit(double amount)
{
	
	if(amount <= account::getBalance())
	{
		cout << fixed << setprecision(2) << "$" << *feeForTransaction << " transaction fee charged." << endl;

		account::debit(amount + *feeForTransaction);//invokes the base class debit 
		
	}
	
}

//Credit
void checkingaccount::credit(double amount)
{	
	

	if(amount < 0.00)
	{
		cout << "Error! Amount can't be negative" << endl;
	}
	else
	{	
		account::credit(amount - *feeForTransaction);//invokes the base class credit
		//account::setBalance(getBalance() - feeForTransaction);
		cout << fixed << setprecision(2) << "$" << *feeForTransaction << " transaction fee charged." << endl;

	}
}
