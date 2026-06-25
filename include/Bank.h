#pragma once
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "CreditAccount.h"
#include "BankException.h"
#include "Report.h"
#include <unordered_map>
#include <memory>
#include <string>
#include <vector>

class Bank {
private:
	std::unordered_map<int, std::unique_ptr<Account>> accounts_;
	int nextId_;
	Account* findAccount(int id);
	const Account* findAccount(int id) const;
public:
	Bank();
	int createAccount(int type, const std::string& owner, double balance, double extra);
	void deposit(int id, double amount);
	void withdraw(int id, double amount);
	void transfer(int fromId, int toId, double amount);
	void printAccountInfo(int id) const;
	void printAllAccounts() const;
	void printTransactionHistory(int id) const;
	size_t getAccountCount() const;
};