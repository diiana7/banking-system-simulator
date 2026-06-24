#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>

template <typename T>
class Report {
private:
	std::vector<T> items_;
public:
	Report(const std::vector<T>& items)
		:items_(items){ }

	void printAll() const {
		for (const auto& i : items_)
			std::cout << i << "\n";
	}

	std::vector<T> filterBy(std::function<bool(const T&)> predicate) const {
		std::vector<T> result;
		std::copy_if(items_.begin(), items_.end(), back_inserter(result), predicate);
		return result;
	}

	size_t getCount() const {
		return items_.size();
	}
};