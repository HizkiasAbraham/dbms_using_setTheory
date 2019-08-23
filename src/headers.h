#include <string>
#include <vector>

#define DB_DirPath "../../dbms_dbs"

using std::vector;
using std::string;

// parse commands supplied by the client
vector<string> parseQuery(string query);
// create database
void createDatabase(string dbName);
// create table
void createTable(string tableName, vector<string> columns);
// insert into table
void insertIntoTable(string tableName, vector<string> params);
// select from table
void selectFrom(string tableName, vector<string> filters);
// delete from table
void deleteFrom(string tableName, vector<string> filters);
// update
void updateTable(string tableName, vector<string> filters);
// show
void showDbsOrTables(string entity);
// use
void use(string dbName);

