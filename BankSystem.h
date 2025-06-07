#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H
#include "BankAccount.h"
#include <vector>

class BankSystem {
public:
	void addAccount(const std::string& name, int accountNumber, double initialBalance);
	BankAccount* findAccount(int accountNumber);
	void transferFunds(int senderAcc, int receiverAcc, double amount);
	void displayAllAccounts() const;
	void DisplayMenu();
        void HandleChoice(int choice);
private:
	std::vector<BankAccount> database;
};

#endif
