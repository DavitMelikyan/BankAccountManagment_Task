#include "BankAccount.h"

void BankAccount::deposit(double amount) {
	if (amount < 0) {
		std::cout << "You can't deposit negative amount of money\n";
		return;
	}
	balance += amount;
}	

bool BankAccount::withdraw(double amount) {
	if (amount < 0) {
                std::cout << "You can't withdraw negative amount of money\n";
		return false;
        }
	if (amount > balance) {
		std::cout << "There is not enough money on your balance\n";
		return false;
	} 
	balance -= amount;
	return true;
}

void BankAccount::display() const {
	std::cout << "Details of Bank Account:\n";
	std::cout << "Holder: "<< accountHolder << std::endl;
	std::cout << "Account number: " << accountNumber << std::endl;
	std::cout << "Balance: " << balance << std::endl;
}

int BankAccount::getAccountNumber() const {
	return accountNumber;
}

double BankAccount::getBalance() const {
        return balance;
}
