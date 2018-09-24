#include "savingsaccount.h"
#include "account.h"
#include <iostream>
#include <string>
using namespace std;

//Default Constructor
savingsaccount::savingsaccount()
{
	interestRate = new double(0.00);
}

//Parameterized constructor
savingsaccount::savingsaccount(double balance, double _interestRate)

	:account(balance)
	{
	
		if(_interestRate < 0.00 && _interestRate > 1.00)
		{
			interestRate = new double(0.00);
			cout << "Interest rate is out of range [0, 1.0]!" << endl;
		}
		else
		{
			interestRate = new double(_interestRate);
		}
	}


//Destructor
savingsaccount::~savingsaccount()
{
	delete interestRate;
}

//Interest rate calculation
double savingsaccount::calcInterest()
{
	
	return getBalance() * (*interestRate);

}
