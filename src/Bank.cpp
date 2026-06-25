#include "Bank.h"

Bank::Bank() : nextId_(1) { }

Account* Bank::findAccount(int id) {
	auto it = accounts_.find(id);
	if (it == accounts_.end())
		throw BankException("Account not found");
	return it->second.get();
}

const Account* Bank::findAccount(int id) const {
	auto it = accounts_.find(id);
	if (it == accounts_.end())
		throw BankException("Account not found");
	return it->second.get();
}

int Bank::createAccount(int type, const std::string& owner, double balance, double extra) {
	int id = nextId_;
	switch (type) {
		case 1:
			accounts_.emplace(id, std::make_unique<SavingsAccount>(id, owner, balance, extra));
			break;
		case 2:
			accounts_.emplace(id, std::make_unique<CheckingAccount>(id, owner, balance, extra));
			break;
		case 3:
			accounts_.emplace(id, std::make_unique<CreditAccount>(id, owner, balance, extra));
			break;
		default:
			throw BankException("Unknown account type");
	}
	nextId_++;
	return id;
}

void Bank::deposit(int id, double amount) {
	Account* acc = findAccount(id);
	acc->deposit(amount);
}


void Bank::withdraw(int id, double amount) {
	Account* acc = findAccount(id);
	acc->withdraw(amount);
}

void Bank::transfer(int fromId, int toId, double amount) {
	Account* from = findAccount(fromId);
	Account* to = findAccount(toId);

	from->withdraw(amount);
	to->deposit(amount);
}

void Bank::printAccountInfo(int id) const {
	const Account* acc = findAccount(id);
	acc->printInfo();
}

void Bank::printAllAccounts() const {
	for (const auto& pair : accounts_)
		pair.second->printInfo();
}

void Bank::printTransactionHistory(int id) const {
	const Account* acc = findAccount(id);
	const auto& transaction = acc->getTransaction();

	Report<Transaction> report(transaction);
	report.printAll();
}

size_t Bank::getAccountCount() const {
	return accounts_.size();
}