#pragma once
#include <string>
#include <iosfwd>

class Transaction {
public:
	enum class TransactionType {
		Deposit,
		Withdraw,
		Transfer
	};
private:
	TransactionType type_;
	double amount_;
	std::string date_;
	std::string description_;
public:
	Transaction(TransactionType type, double amount, const std::string& description);

	TransactionType getTransactionType() const;
	double getAmount() const;
	const std::string& getDate() const;
	const std::string& getDescription() const;

	friend std::ostream& operator<<(std::ostream& os, const Transaction& t);
};