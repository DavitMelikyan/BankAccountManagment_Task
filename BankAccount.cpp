#include "BankAccount.h"

BankAccount::BankAccount() : accountHolder{"Unknown"}, accountNumber{0}, balance{0.0} {}

BankAccount::BankAccount(std::string Name, int Number, double initialBalance) : accountHolder{Name}, accountNumber{Number}, balance{initialBalance} {}
       
BankAccount::BankAccount(const BankAccount& src) : accountHolder{src.accountHolder}, accountNumber{src.accountNumber}, balance{src.balance} {}
       
BankAccount::BankAccount(std::string& Name, int Number) : accountHolder(Name), accountNumber(Number), balance(0.0) {}

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
