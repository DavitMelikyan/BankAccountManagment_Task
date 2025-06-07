#include "BankSystem.h"

void BankSystem::addAccount(const std::string& name, int accountNumber, double initialBalance) {
	database.emplace_back(name, accountNumber, initialBalance);	
}

BankAccount* BankSystem::findAccount(int accountNumber) {
	for (int i = 0; i < database.size(); ++i) {
		if (database[i].getAccountNumber() == accountNumber) {
			return &database[i];
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
	for (int i = 0; i < database.size(); ++i) {
		database[i].display();
	}
}

void BankSystem::HandleChoice(int choice) {
       switch (choice) {
                case 1: {
                        std::string Name;
                        int Number = 0;
                        std::cout << "Please enter the information about the user\n";
                        std::cout << "Holder Name: ";
                        std::cin >> Name;
                        std::cout << "Account number: ";
                        std::cin >> Number;
                        addAccount(Name, Number, 0.0);
                        break;
                } case 2: {
                        displayAllAccounts();
                        break;
                } case 3: {
                        int accountNumber = 0;
                        std::cout << "Enter the account number: ";
                        std::cin >> accountNumber;
                        BankAccount* account = findAccount(accountNumber);
			if (account) {
				account->display();
			}
                        break;
                } case 4: {
			int accountNumber = 0;
			double amount = 0;
			std::cout << "Enter the account number: ";
                        std::cin >> accountNumber;
                        std::cout << std::endl;
                        BankAccount* depaccount = findAccount(accountNumber);
			if (depaccount) {
				std::cout << "Enter the sum of deposit: ";
				std::cin >> amount;
				depaccount->deposit(amount);
			}
			break;
		} case 5: {
			int accountNumber = 0;
                        double amount = 0;
                        std::cout << "Enter the account number: ";
                        std::cin >> accountNumber;
                        std::cout << std::endl;
                        BankAccount* withaccount = findAccount(accountNumber);
                        if (withaccount) {
                                std::cout << "Enter the sum of withdrawal: ";
                                std::cin >> amount;
                                withaccount->withdraw(amount);
                        }
                        break;
		} case 6: {
			int accountNumber = 0;
                        double amount = 0;
                        std::cout << "Enter the account number: ";
                        std::cin >> accountNumber;
                        std::cout << std::endl;
                        BankAccount* balaccount = findAccount(accountNumber);
			if (balaccount) {
				std::cout << "Account balance: " << balaccount->getBalance() << std::endl;
			}
			break;
		} case 7: {
			int sender = 0;
			int receiver = 0;
			double amount = 0;
			std::cout << "Enter sender account number: ";
            		std::cin >> sender;
            		std::cout << "Enter receiver account number: ";
            		std::cin >> receiver;
            		std::cout << "Enter amount to transfer: ";
            		std::cin >> amount; 
			transferFunds(sender, receiver, amount);
           	 	break;
		} default:
			std::cout << "Invalid choice\n";
                        break;
         }
}

void BankSystem::DisplayMenu() {
        int choice = 1;
	while (true) {
        	std::cout << "1. Add new account to the database\n2. Display all account in database\n3. Find account in database\n4. Deposit money\n5. Withdraw money\n6. Get account balance\n7. Transfer funds between accounts\n8. Exit" << std::endl;
        	std::cout << "Enter choice: ";
        	std::cin >> choice;
        	std::cout << std::endl;
        	if (choice < 1 || choice > 8) {
               		std::cout << "Invalid choice\n";
			choice = 0;
                	continue;
        	}
		if (choice == 8) {
            		std::cout << "Bank system closed\n";
            		break;
        	}
        	HandleChoice(choice);
	}
}	

