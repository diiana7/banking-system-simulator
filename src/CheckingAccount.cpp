#include "CheckingAccount.h"
#include "BankException.h"
#include <iostream>
#include <stdexcept>

CheckingAccount::CheckingAccount(int id, const std::string& owner, double balance, double overdraftLimit)
	:Account(id, owner, balance), overdraftLimit_(overdraftLimit){ 
	if (overdraftLimit_ < 0)
		throw std::invalid_argument("Invalid overdraft limit");
}

void CheckingAccount::withdraw(double amount) {
	validateAmount(amount);

	if (amount > balance_ + overdraftLimit_)
		throw BankException("Overdraft limit exceeded");
	else
		balance_ -= amount;

	addTransaction(Transaction::TransactionType::Withdraw,
		amount,
		"Checking withdrawal");
}

double CheckingAccount::getOverdraftLimit() const {
	return overdraftLimit_;
}

double CheckingAccount::getAvailableFunds() const {
	return balance_ + overdraftLimit_;
}

void CheckingAccount::printInfo() const {
	std::cout << "Type: CheckingAccount" << "\n";
	Account::printInfo();
	std::cout << "Overdraft limit: " << overdraftLimit_ << "\n";
	std::cout << "Available funds: " << getAvailableFunds() << "\n";
}