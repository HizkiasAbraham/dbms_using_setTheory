#include <string>
#include <vector>


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

