#pragma once
#include <string>
#include <vector>
#include <iosfwd>

class Transaction;

class Account {
protected:
	int id_;
	std::string owner_;
	double balance_;
public:
	Account(int id, const std::string& owner, double balance);
	virtual ~Account();

	virtual void deposit(double amount);
	virtual void withdraw(double amount);

	int getId() const;
	std::string getOwner() const;
	double getBalance() const;

	const std::vector<Transaction>& getTransaction() const;

	virtual void printInfo() const;
	friend std::ostream& operator<<(std::ostream& os, const Account& acc);
private:
	void validateAmount(double amount) const;
};