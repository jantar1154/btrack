#include "sql.h"
#include "spending_data.h"
#include <algorithm>
#include <cstring>
#include <sqlite3.h>
#include <iostream>

Sql::Sql(const std::string &filename) {
    int status = sqlite3_open(filename.c_str(), &sql);
    // Initialise Expenses table
    strcpy(sql_query, "CREATE TABLE IF NOT EXISTS Expenses ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "amount INTEGER NOT NULL, "
        "name TEXT NOT NULL, "
        "description TEXT NOT NULL"
        ");");
    char *error_msg;
    status = sqlite3_exec(sql, sql_query, nullptr, 0, &error_msg);
    if (status != SQLITE_OK) {
        std::cerr << "Error while creating table " << filename << std::endl;
        sqlite3_free(error_msg);
    }
    
    // exit(status);
    insert_expense(Expense(100, "Karel 2", "123hioasdf"));
}

std::string Sql::get_all_expenses() {
    return "";
}

void Sql::insert_expense(const Expense &expense) {
    strcpy(sql_query,
        "INSERT INTO Expenses"
        "(amount, name, description)"
        "VALUES"
        "(?1, ?2, ?3);"
    );

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(sql, sql_query, 0xFF, &stmt, nullptr);

    const int name_size = expense.get_name().length();
    const int description_size = expense.get_name().length();

    const std::string name { expense.get_name() };
    const std::string description { expense.get_description() };

    sqlite3_bind_int(stmt, 1, expense.get_amount());
    sqlite3_bind_text(stmt, 2, name.c_str(), name_size, nullptr);
    sqlite3_bind_text(stmt, 3, description.c_str(), description_size, nullptr);

    while (SQLITE_OK == sqlite3_step(stmt)) { }

    sqlite3_finalize(stmt);

    
    // int status = sqlite3_exec(sql, sql_query, nullptr, 0, nullptr);
    // exit(status);
}

Sql::~Sql() {
    sqlite3_close(sql);
    delete[] sql_query;
}
