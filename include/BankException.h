#pragma once
#include <stdexcept>
#include <string>

class BankException :public std::runtime_error {
public:
	explicit BankException(const std::string& message)
		: std::runtime_error(message){ }

};