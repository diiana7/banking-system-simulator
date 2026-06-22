#pragma once
#include "Account.h"

class CreditAccount :public Account {
private:
	double creditLimit_;
	double debt_;
public:
	CreditAccount(int id, const std::string& owner, double balance, double creditLimit);

	void deposit(double amount) override;
	void withdraw(double amount) override;

	double getCreditLimit() const;
	double getDebt() const;

	void printInfo() const override;
};