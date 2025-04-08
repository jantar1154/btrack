#include "sql.h"
#include "spending_data.h"
#include "util.h"
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
}

static int callback(void *exp, int argc, char **argv, char **colname) {
    bt::Vector<Expense> *expenses = static_cast<bt::Vector<Expense>*>(exp);
    // exit(69);
    for (int i = 0; i < argc; i += 4) {
        int32_t amount = static_cast<int32_t> (atoi(argv[i + 1]));
        std::string name = argv[i + 2];
        std::string description = argv[i + 3];
        expenses->add(Expense{amount, name, description});
    }
    return SQLITE_OK;
}

bt::Vector<Expense> Sql::get_all_expenses() {
    bt::Vector<Expense> expenses;
    strcpy(sql_query, "SELECT * FROM Expenses;");
    char *errmsg;

    // Callback gets called for every row
    sqlite3_exec(sql, sql_query, callback, &expenses, &errmsg);

    return expenses;
}

void Sql::insert_expense(const Expense &expense) {
    // TODO: more information on expenses
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

    // Parameter binding
    sqlite3_bind_int(stmt, 1, expense.get_amount());
    sqlite3_bind_text(stmt, 2, name.c_str(), name_size, nullptr);
    sqlite3_bind_text(stmt, 3, description.c_str(), description_size, nullptr);

    // Do every row
    while (SQLITE_OK == sqlite3_step(stmt)) { }

    sqlite3_finalize(stmt);
}

Sql::~Sql() {
    sqlite3_close(sql);
    delete[] sql_query;
}
