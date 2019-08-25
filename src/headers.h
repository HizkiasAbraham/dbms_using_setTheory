#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/variant.hpp>

using std::vector;
using std::string;
using boost::filesystem::path;
using boost::variant;

string DB_DirPath = "../../dbms_dbs";
// parse commands supplied by the client
vector<string> parseQuery(string query);
// create database
void createDatabase(string dbName);
// create table
void createTable(vector<string> dbPath, string tableName, vector<string> columns);
// insert into table
void insertIntoTable(vector<string> dbPath, string tableName, vector<string> params);
// select from table
void selectFrom(vector<string> dbPath, vector<string> query);
// delete from table
void deleteFrom(string tableName, vector<string> filters);
// update
void updateTable(string tableName, vector<string> filters);
// show
void showDbsOrTables(string entity, vector<string> currentPath);
// build path from paths string
path buildPath(vector<string> pathVector);
// get column names of a table
vector<string> getColumnNames(vector<string> dbPath, string tableName);
// builder function to build a vector of variants from a column file
vector<variant<int, string>> buildColumn(string colfileValue);
// show error message
void showErrorMessage();

