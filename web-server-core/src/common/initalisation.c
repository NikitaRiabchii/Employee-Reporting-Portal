#include "./sqlite_db/sqlite3.h"
#include <stdio.h>
#define relative_path_to_users "../../db/users.db"
#define relative_path_to_log "../../db/log.db"
#define relative_path_to_invalids "../../db/invalids.db"

void initialisation_db(void){
    sqlite3 *db_users;
    sqlite3 *db_log;
    sqlite3 *db_invalids;
    char *err_msg = 0;

    // Open or create the users database
    if (sqlite3_open(relative_path_to_users, &db_users) != SQLITE_OK) {
        fprintf(stderr, "Cannot open users database: %s\n", sqlite3_errmsg(db_users));
        return;
    }

    // Open or create the log database
    if (sqlite3_open(relative_path_to_log, &db_log) != SQLITE_OK) {
        fprintf(stderr, "Cannot open log database: %s\n", sqlite3_errmsg(db_log));
        sqlite3_close(db_users);
        return;
    }

    // Open or create the invalids database
    if (sqlite3_open(relative_path_to_invalids, &db_invalids) != SQLITE_OK) {
        fprintf(stderr, "Cannot open invalids database: %s\n", sqlite3_errmsg(db_invalids));
        sqlite3_close(db_users);
        sqlite3_close(db_log);
        return;
    }

    // Create users table if it doesn't exist
    const char *sql_create_users = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT NOT NULL);";
    if (sqlite3_exec(db_users, sql_create_users, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error creating users table: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    // Create log table if it doesn't exist
    const char *sql_create_log = "CREATE TABLE IF NOT EXISTS log (id INTEGER PRIMARY KEY, message TEXT NOT NULL);";
    if (sqlite3_exec(db_log, sql_create_log, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error creating log table: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    // Create invalids table if it doesn't exist
    const char *sql_create_invalids = "CREATE TABLE IF NOT EXISTS invalids (id INTEGER PRIMARY KEY, reason TEXT NOT NULL);";
    if (sqlite3_exec(db_invalids, sql_create_invalids, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error creating invalids table: %s\n", err_msg);}}