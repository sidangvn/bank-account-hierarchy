#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <iostream>
#include "account.h"

class savingsaccount: public account
{
	public:
		savingsaccount();
		savingsaccount(double balance, double interestRate);
		~savingsaccount();
		double calcInterest();
	private:
		double *interestRate;
	
	
	
};

#endif
