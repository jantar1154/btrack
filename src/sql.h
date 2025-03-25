#pragma once
#include "spending_data.h"
#include "util.h"
#include <sqlite3.h>
#include <string>

class Sql {
private:
    sqlite3 *sql;
    // To prevent repeated allocation
    char *sql_query = new char[0xFF];

public:
    Sql() = delete;
    Sql(const std::string &filename);
    bt::Vector<Expense> get_all_expenses();
    void insert_expense(const Expense&);
    ~Sql();
};
