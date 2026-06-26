#include <iostream>
#include "Bank.h"

int main() {
    std::cout << "Banking System Simulator" << std::endl;

    Bank acc;

    while (true) {
        std::cout << "1. Create account" << "\n" << "2. Deposit" << "\n" << "3. Withdraw" << "\n" << "4. Transfer" << "\n"
            << "5. Account information" << "\n" << "6. Transaction history" << "\n" << "7. Print all accounts" << "\n"
            << "8. Account count" << "\n" << "9. Exit" << "\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:{
                std::cout << "Account type:" << "\n" << "1. Savings" << "\n" << "2. Checking" << "\n" << "3. Credit" << "\n";
                int typeChoice;
                std::cin >> typeChoice;
                std::string owner;
                double balance;
                std::cout << "Enter" << "\n";
                std::cout << "Your name:" << "\n";
                std::cin >> owner;
                std::cout << "Balance:" << "\n";
                std::cin >> balance;
                switch (typeChoice) {
                case 1: {
                    try {
                        double interestRate;
                        std::cout << "Interest rate:" << "\n";
                        std::cin >> interestRate;
                        int id = acc.createAccount(1, owner, balance, interestRate);
                        std::cout << "Account created." << "\n" << "Your id: " << id << "\n";
                    }
                    catch (const BankException& e) {
                        std::cout << "Error: " << e.what() << "\n";
                    }
                    break;
                }
                case 2: {
                    try {
                        double overdraftLimit;
                        std::cout << "Overdraft limit:" << "\n";
                        std::cin >> overdraftLimit;
                        int id = acc.createAccount(2, owner, balance, overdraftLimit);
                        std::cout << "Account created." << "\n" << "Your id: " << id << "\n";
                    }
                    catch (const BankException& e) {
                        std::cout << "Error: " << e.what() << "\n";
                    }
                    break;
                }
                case 3: {
                    try {
                        double creditLimit;
                        std::cout << "Credit limit:" << "\n";
                        std::cin >> creditLimit;
                        int id = acc.createAccount(3, owner, balance, creditLimit);
                        std::cout << "Account created." << "\n" << "Your id: " << id << "\n";
                    }
                    catch (const BankException& e) {
                        std::cout << "Error: " << e.what() << "\n";
                    }
                    break;
                }
                default:
                    std::cout << "Invalid type\n";
                }
                break;
            }

            case 2: {
                try {
                    int id;
                    std::cout << "Your id:" << "\n";
                    std::cin >> id;
                    double amount;
                    std::cout << "Amount:" << "\n";
                    std::cin >> amount;
                    acc.deposit(id, amount);
                }
                catch (const BankException& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
                break;
            }

            case 3: {
                try {
                    int id;
                    std::cout << "Your id:" << "\n";
                    std::cin >> id;
                    double amount;
                    std::cout << "Amount:" << "\n";
                    std::cin >> amount;
                    acc.withdraw(id, amount);
                }
                catch (const BankException& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
                break;
            }

            case 4:{
                try {
                    int fromId, toId;
                    double amount;
                    std::cout << "From id:" << "\n";
                    std::cin >> fromId;
                    std::cout << "To id:" << "\n";
                    std::cin >> toId;
                    std::cout << "Amount:" << "\n";
                    std::cin >> amount;
                    acc.transfer(fromId, toId, amount);
                }
                catch (const BankException& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
                break;
            }

            case 5:{
                try {
                    int id;
                    std::cout << "Your id:" << "\n";
                    std::cin >> id;
                    acc.printAccountInfo(id);
                }
                catch (const BankException& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
                break;
            }
                
            case 6:{
                try {
                    int id;
                    std::cout << "Your id:" << "\n";
                    std::cin >> id;
                    acc.printTransactionHistory(id);
                }
                catch (const BankException& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
                break;
            }
                
            case 7:{
                try {
                    acc.printAllAccounts();
                }
                catch (const BankException& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
                break;
            }
                
            case 8:{
                try {
                    std::cout << "Account count: " << acc.getAccountCount();
                }
                catch (const BankException& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
                break;
            }

            case 9:
                return 0;

            default:
                std::cout << "Invalid choice" << "\n";
                break;
        }
    }
    return 0;
}