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
	BankAccount();
	BankAccount(std::string Name, int Number, double initialBalance);
	BankAccount(const BankAccount& src);
	BankAccount(std::string& Name, int Number);
	~BankAccount() = default;
	void deposit(double amount);
	bool withdraw(double amount);
	void display() const;
	int getAccountNumber() const;
	double getBalance() const;
};	

#endif
