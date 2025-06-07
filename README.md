# BankAccountManagment_Task

Code consists of 5 parts - 2 headers with their implementations and main.
BankAccount.h includes the class which holds the information about bank account. It also has few constructors and declarations of functions which are implemented in BankAccount.cpp file.

BankSystem.h includes the class which holds the database of all bank account in the system in vector. It has declarations of functions which let user to communicate with database and accounts and also it has the declarations for user interface functions. These function's definitions are in BankSystem.cpp file.

main.cpp just calls the menu which does the whole work.

To compile the whole thing you need to use g++ -std=c++20 main.cpp BankSystem.cpp BankAccount.cpp

After ./a.out the menu of choices will appear. You will have 8 options. Everyone (except exit) does something. If you enter a number out of range the menu will appear again and again until you won't choose the exit option (8) yourself. 

