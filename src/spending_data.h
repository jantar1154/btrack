#pragma once

#include <string>
#include <vector>
#include "util.h"

class Expense {
protected:
    int32_t amount;

public:
    Expense() = delete;
    Expense(int32_t);

    int32_t get_amount() const;
};

class SpendingData {
    bt::Vector<Expense> expenses;

public:
    SpendingData() = delete;
    SpendingData(const std::string &filename);
    ~SpendingData();
};
