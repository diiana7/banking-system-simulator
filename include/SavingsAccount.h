#pragma once
#include "Account.h"

class SavingsAccount : public Account {
private:
	double interestRate_;
public:
	SavingsAccount(int id, const std::string& owner, double balance, double interestRate);

	void applyInterest();

	double getInterestRate() const;

	void printInfo() const override;
};