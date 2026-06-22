#include "Account.h"
#include <stdexcept>
#include <iostream>

Account::Account(int id, const std::string& owner, double balance)
	:id_(id), owner_(owner), balance_(balance){ }

Account::~Account() { }

void Account::validateAmount(double amount) const {
	if (amount <= 0)
		throw std::invalid_argument("Wrong amount");
}

void Account::addTransaction(Transaction::TransactionType type, double amount, const std::string& description) {
	transactions_.emplace_back(type, amount, description);
}

void Account::deposit(double amount) {
	validateAmount(amount);
	balance_ += amount;

	addTransaction(Transaction::TransactionType::Deposit,
		amount,
		"Deposit");
}

void Account::withdraw(double amount) {
	validateAmount(amount);
	if (balance_ >= amount)
		balance_ -= amount;
	else
		throw std::runtime_error("Amount is more than your balance");

	addTransaction(Transaction::TransactionType::Withdraw,
		amount,
		"Withdraw");
}

int Account::getId() const {
	return id_;
}

std::string Account::getOwner() const {
	return owner_;
}

double Account::getBalance() const {
	return balance_;
}

const std::vector<Transaction>& Account::getTransaction() const {
	return transactions_;
}

void Account::printInfo() const {
	std::cout << "Id: " << id_ << "\n" << "Owner: " << owner_ << "\n" << "Balance: " << balance_ << "\n";
}

std::ostream& operator<<(std::ostream& os, const Account& acc) {
	acc.printInfo();
	return os;
}
