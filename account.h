#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class account
{
	public:
		account();
		account(double balance);
		virtual ~account();
		void setBalance(double);
		double getBalance();
		virtual void debit(double amount);
		virtual void credit(double amount);
		
	private:
		double* balance;	
	
	
};

#endif //!ACCOUNT_H
