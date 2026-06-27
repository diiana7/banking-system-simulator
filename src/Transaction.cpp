#include "Transaction.h"
#include <ctime>
#include <iostream>

static std::string getCurrentTime() {
	time_t now = time(nullptr); //отримання поточного часу
	char buffer[26];
	ctime_s(buffer, sizeof(buffer), &now); //перетворення в текст
	std::string result(buffer);
	if (!result.empty() && result.back() == '\n')// видаляємо \n з кінця
		result.pop_back();
	return result;
}

static std::string typeToString(Transaction::TransactionType type) {
	switch (type) {
		case Transaction::TransactionType::Deposit:
			return "Deposit";
		case Transaction::TransactionType::Transfer:
			return "Transfer";
		case Transaction::TransactionType::Withdraw:
			return "Withdraw";
	}
	return "Unknown";
}

Transaction::Transaction(TransactionType type, double amount, const std::string& description)
	:type_(type), amount_(amount), date_(getCurrentTime()), description_(description) {
}

Transaction::TransactionType Transaction::getTransactionType() const {
	return type_;
}
double Transaction::getAmount() const {
	return amount_;
}
const std::string& Transaction::getDate() const {
	return date_;
}
const std::string& Transaction::getDescription() const {
	return description_;
}

std::ostream& operator<<(std::ostream& os, const Transaction& t) {
	os << typeToString(t.type_) << " | " << t.amount_ << " | " << t.date_ << " | " << t.description_;
	return os;
}