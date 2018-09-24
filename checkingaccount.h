#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include <iostream>
#include "account.h"
#include "savingsaccount.h"


class checkingaccount : public account
{
	public:
		checkingaccount();
		checkingaccount(double balance, double _feeForTransaction);
		virtual ~checkingaccount();
		virtual void debit(double amount);
		virtual void credit(double amount);
	private:
		double *feeForTransaction;
		
};

#endif //!CHECKINGACCOUNT_H

