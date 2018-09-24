#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "checkingaccount.h"
#include "savingsaccount.h"
#include "account.h"

using namespace std;

int NUM = 6; //total 6 accounts

int main()
{
	//vectors declaration
	vector<account*> member;//account class

	int i;
	double balanceIn; //input balance
	double interestRateIn; //input interest rate
	double fee; //fee for transaction input
	
	for(i = 1; i <= NUM; i++)
	{	//alternative input
		if(i % 2 == 0) //savings account input
		{
			cout << "Savings Account " << i << endl;
			cout << "Please enter the balance: ";
			cin >> balanceIn;
			cout << "Please enter the interest rate: ";
			cin >> interestRateIn;
			cout << endl << endl;
			
			//create a pointer to savingsaccount list
			savingsaccount *accounts = new savingsaccount(balanceIn, interestRateIn);
			member.push_back(accounts); //push item into the list
		
			//save.push_back(accounts); //late using for getting the interest fee

		}
		else //checking account input
		{
			cout << "Checking account " << i << endl;
			cout << "Please enter the balance: ";
			cin >> balanceIn;
			
			cout << "Please enter the transaction fee: ";
			cin >> fee;
			cout << endl << endl;

			checkingaccount *accounts = new checkingaccount(balanceIn, fee);
			member.push_back(accounts);//push item into the list
					
			
		}
	}
	
	int j;
	double moneyOut, moneyIn;
	
	for(j = 1; j <= NUM; j++)
	{	//alternative output
		if(j % 2 != 0) //checking account
		{
			cout << fixed << setprecision(2) << "Account "<< j << " balance: $" << member[j - 1] -> getBalance() << endl;
			cout <<"Enter an amount to withdraw from Account " << j << " : $";
			cin >> moneyOut;
			member[j - 1] -> debit(moneyOut); //add the amount into checking account debit function
			
			cout << "Enter an amount to deposit into Account " << j << ": $";
			cin >> moneyIn;
			member[j - 1] -> credit(moneyIn);//add the amount into checking account credit function

			cout << fixed << setprecision(2) << "Updated Account " << j << " balance: $" << member[j - 1] -> getBalance() << endl << endl << endl;



				
		}
		if(j % 2 == 0) //savingsaccount
		{
			cout << fixed << setprecision(2) << "Account "<< j << " balance: $" << member[j - 1] -> getBalance() << endl;
			cout <<"Enter an amount to withdraw from Account " << j << ": $";
			cin >> moneyOut;
			member[j - 1] -> debit(moneyOut); //add the amount into savings account debit function
	
			cout << "Enter an amount to deposit into Account " << j << ": $";
			cin >> moneyIn;
			member[j - 1] -> credit(moneyIn);//add the amount into savings account function
			
		

			cout << fixed << setprecision(2) << "Adding $" << member[j -1] -> getBalance() << " interest to Account " << j << endl;	


			cout << fixed << setprecision(2) << "Updated Account " << j << " balance: $" << (member[j - 1] -> getBalance()) << endl << endl << endl;	
			
		}
	}

	
	
	

	return 0;
	
	
	
	
}
