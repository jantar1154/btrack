#pragma once

#include <string>
#include <vector>
#include "util.h"

class Expense {
protected:
    size_t id;

    // How much money was spent
    int32_t amount;

    // Name of the transaction
    std::string name;

    // Description
    std::string description;

    bt::Datetime datetime;

public:
    Expense() = delete;
    explicit Expense(size_t, int32_t, const std::string&, const std::string&, const bt::Datetime&);
    Expense(const Expense &other);
    Expense(Expense &&other);

    size_t get_id() const;
    int32_t get_amount() const;
    std::string get_name() const;
    std::string get_description() const;
    bt::Datetime get_datetime() const;

    Expense operator = (const Expense &other);
    Expense operator = (Expense &&other);
};

class SpendingData {
protected:
    std::vector<Expense> expenses;

public:
    SpendingData() = delete;
    SpendingData(const std::string &filename);
    ~SpendingData();

    // TODO
    void save() const;

    // returns non modifiable vector of expenses
    std::vector<Expense> get_expenses() const;
};
