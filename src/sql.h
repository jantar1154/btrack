#pragma once
#include "spending_data.h"
#include "util.h"
#include <sqlite3.h>
#include <string>

class Sql {
private:
    sqlite3 *sql;
    // To prevent repeated allocation
    // Must be char* because sql wants it like that
    char *sql_query = new char[0xFF];

public:
    Sql() = delete;
    Sql(const std::string &filename);

    // SELECT * FROM Expenses;
    std::vector<Expense> get_all_expenses();

    // INSERT INTO Expenses
    void insert_expense(const Expense&);

    ~Sql();
};
