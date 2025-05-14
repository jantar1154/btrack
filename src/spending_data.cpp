#include "spending_data.h"
#include "util.h"
#include "sql.h"

#include <iostream>

using std::string;

Expense::Expense(size_t id, int32_t amount, const string& name, const string& description, const bt::Datetime& datetime):
    id {id},
    amount {amount},
    name {name},
    description {description},
    datetime {datetime} { }

Expense::Expense(const Expense& other):
    Expense (
        other.id,
        other.amount,
        other.name,
        other.description,
        other.datetime
    ) { }

Expense::Expense(Expense&& other):
    Expense (
        std::move(other.id),
        std::move(other.amount),
        std::move(other.name),
        std::move(other.description),
        std::move(other.datetime)
    ) {}

size_t Expense::get_id() const { return id; }
int32_t Expense::get_amount() const { return amount; }
string Expense::get_name() const { return name; }
string Expense::get_description() const { return description; }
bt::Datetime Expense::get_datetime() const { return datetime; }

// TODO
void SpendingData::save() const {}

std::vector<Expense> SpendingData::get_expenses() const {
    return expenses;
}

SpendingData::SpendingData(const std::string &filename) {
    Sql sql(filename);
    // Populate expenses with SELECT
    expenses = sql.get_all_expenses();
    std::cerr << "SIZE: " << expenses.size() << std::endl;
}

Expense Expense::operator = (const Expense &other) { return Expense { other }; }

Expense Expense::operator = (Expense &&other) { return Expense { other }; }

SpendingData::~SpendingData() { }
