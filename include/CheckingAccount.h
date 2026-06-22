#pragma once
#include "Account.h"

class CheckingAccount :public Account {
private:
	double overdraftLimit_;
public:
	CheckingAccount(int id, const std::string& owner, double balance, double overdraftLimit);

	void withdraw(double amount) override;

	double getOverdraftLimit() const;
	double getAvailableFunds() const;

	void printInfo() const override;
};