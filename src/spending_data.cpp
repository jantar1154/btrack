#include "spending_data.h"
#include "util.h"
#include "sql.h"

using std::string;

Expense::Expense(int32_t amount, const string &name, const string &description):
    amount(amount),
    name(name),
    description(description) { }

Expense::Expense(const Expense &other) {
    amount = other.amount;
    name = other.name;
    description = other.description;
}

Expense::Expense(Expense &&other) {
    amount = other.amount;
    name = other.name;
    description = other.description;
}

int32_t Expense::get_amount() const { return amount; }
string Expense::get_name() const { return name; }
string Expense::get_description() const { return description; }

// TODO
void SpendingData::save() const {}

SpendingData::SpendingData(const std::string &filename) {
    Sql sql(filename);
    expenses = sql.get_all_expenses();
}

Expense Expense::operator = (const Expense &other) {
    return Expense { other };
}

Expense Expense::operator = (Expense &&other) {
    return Expense { other };
}

SpendingData::~SpendingData() {
}
