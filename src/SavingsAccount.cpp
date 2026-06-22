#include "SavingsAccount.h"
#include <iostream>
#include <stdexcept>

SavingsAccount::SavingsAccount(int id, const std::string& owner, double balance, double interestRate)
	:Account(id, owner, balance), interestRate_(interestRate){
	if (interestRate_ < 0)
		throw std::invalid_argument("Invalid interest rate");
}

void SavingsAccount::applyInterest() {
	double interest = balance_ * interestRate_ / 100;
	balance_ += interest;

	addTransaction(Transaction::TransactionType::Deposit,
		interest,
		"Interest applied");
}

double SavingsAccount::getInterestRate() const {
	return interestRate_;
}

void SavingsAccount::printInfo() const {
	std::cout << "Type: SavingsAccount" << "\n";
	Account::printInfo();
	std::cout << "Interest rate: " << interestRate_ << "\n";
}