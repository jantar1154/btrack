#pragma once

#include <string>
#include <vector>
#include "util.h"

class Expense {
protected:
    int32_t amount;
    std::string name;
    std::string description;

public:
    Expense() = delete;
    Expense(int32_t, const std::string&, const std::string&);
    Expense(const Expense &other);
    Expense(Expense &&other);

    int32_t get_amount() const;
    std::string get_name() const;
    std::string get_description() const;


    Expense operator = (const Expense &other);
    Expense operator = (Expense &&other);
};

class SpendingData {
protected:
    bt::Vector<Expense> expenses;


public:
    SpendingData() = delete;
    SpendingData(const std::string &filename);
    ~SpendingData();

    // TODO
    void save() const;
};
