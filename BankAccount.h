#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <string>

class BankAccount {
private:	
	std::string accountHolder;  
	int accountNumber;  
	double balance;  
public:
	BankAccount() {
		accountHolder = "Unknown";
		accountNumber = 0;
		balance = 0.0;
	} 
	BankAccount(std::string Name, int Number, double initialBalance) {
		accountHolder = Name;
		accountNumber = Number;
		balance = initialBalance;
	}
	BankAccount(const BankAccount& src) {
		accountHolder = src.accountHolder;
		accountNumber = src.accountNumber;
		balance = src.balance;
	}
	BankAccount(std::string& Name, int Number) : accountHolder(Name), accountNumber(Number), balance(0.0) {
		
	}
	~BankAccount() {
	
	}	
	void deposit(double amount);
	bool withdraw(double amount);
	void display() const;
	int getAccountNumber() const;
	double getBalance() const;
};	

#endif
