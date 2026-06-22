#include "CreditAccount.h"
#include <stdexcept>
#include <iostream>

CreditAccount::CreditAccount(int id, const std::string& owner, double balance, double creditLimit)
	:Account(id, owner, balance), creditLimit_(creditLimit), debt_(0.0) 
{
	if (creditLimit_ < 0)
		throw std::invalid_argument("Invalid credit limit");
}

void CreditAccount::deposit(double amount) {
	validateAmount(amount);

	if (debt_ > 0) {
		if (amount >= debt_) {
			double remaining = amount - debt_;
			debt_ = 0;
			balance_ += remaining;
		}
		else {
			debt_ -= amount;
		}
	}
	else 
		balance_ += amount;
		
	addTransaction(Transaction::TransactionType::Deposit, amount, "Credit deposit");
}


void CreditAccount::withdraw(double amount) {
	validateAmount(amount);

	double available = balance_ + (creditLimit_ - debt_);

	if (amount > available)
		throw std::runtime_error("Exceeding credit limit");
	
	if (amount <= balance_)
		balance_ -= amount;
	else {
		double rest = amount - balance_;
		balance_ = 0;
		debt_ += rest;
	}

	addTransaction(Transaction::TransactionType::Withdraw, amount, "Credit withdraw");
}

double CreditAccount::getCreditLimit() const {
	return creditLimit_;
}

double CreditAccount::getDebt() const {
	return debt_;
}

void CreditAccount::printInfo() const {
	Account::printInfo();
	std::cout << "Credit limit: " << creditLimit_ << "\n";
	std::cout << "Debt: " << debt_ << "\n";
}