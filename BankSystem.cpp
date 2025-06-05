#include "BankSystem.h"

void BankSystem::addAccount(const std::string& name, int accountNumber, double initialBalance) {
	BankAccount newAccount(name, accountNumber, initialBalance);
	database.push_back(newAccount);	
}

BankAccount* BankSystem::findAccount(int accountNumber) {
	for (BankAccount& account : database) {
		if (account.getAccountNumber() == accountNumber) {
			return &account;
		}
	}
	std::cout << "Account not found\n";
	return nullptr; 	
}

void BankSystem::transferFunds(int senderAcc, int receiverAcc, double amount) {
	if (senderAcc == receiverAcc) {
   		std::cout << "Can't transfer to the same account\n";
    		return;
	}
	BankAccount* sender = findAccount(senderAcc);
        BankAccount* receiver = findAccount(receiverAcc);
        if (sender && receiver) {
		if (!sender->withdraw(amount)) {
			std::cout << "Sender doesn't have enough money\n";
			return;
		}
		receiver->deposit(amount);
	}
}

void BankSystem::displayAllAccounts() const {
	for (const BankAccount& account : database) {
		account.display();
	}
}
