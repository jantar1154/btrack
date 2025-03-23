#include "spending_data.h"
#include "util.h"

#include <iostream>

Expense::Expense(int32_t amount):
    amount(amount) { }

int32_t Expense::get_amount() const {
    return amount;
}

SpendingData::SpendingData(const std::string &filename) {
    for (size_t i = 0; i < 1000; ++i) {
        expenses.add(Expense(100 * i));
    }

    std::cout << "at 100: " << expenses.get(100).value().get_amount() << std::endl;
    expenses.remove(100);
    std::cout << "at 100: " << expenses.get(100).value().get_amount() << std::endl;

}

SpendingData::~SpendingData() {
}
