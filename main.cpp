#include "BankAccount.h"
#include "BankSystem.h"

int main() {
    	BankSystem bank;
    	bank.addAccount("Alice Smith", 1001, 500.0);
    	bank.addAccount("John Doe", 1002, 1000.0);
   	bank.displayAllAccounts();
   	bank.findAccount(1001)->deposit(200);
   	bank.findAccount(1002)->withdraw(150);
	bank.transferFunds(1002, 1001, 300);
    	bank.displayAllAccounts();
	return 0;
}  

