#include "headers.h"
#include <string>
#include <vector>
// #include <boost/filesystem.hpp>

// using namespace boost::filesystem;

/*
    creates database
    =================
     - a new directory from the root directory ${DB_DirPath} for 
       database files
 */
void createDatabase(string dbName){
    dbName += "";
}
/*
    shows list of databases or tables already created
 */
void showDbsOrTables(string entity){

}
/*
    select a database to manipulate
 */
void use(string dbName){

}
/*
    creates a table
    ================
     - a new sub directory inside a database directory
       and files for the each columns
 */
void createTable(string tableName, vector<string> columns){

}
/*
    inserts a data to specified columns in the params list
 */
void insertIntoTable(string tableName, vector<string> params){

}
/*
    query from a table with specified filters
 */
void selectFrom(string tableName, vector<string> filters){

}
/*
    delete from a table with specified filters
 */
void deleteFrom(string tableName, vector<string> filters){

}
/*
    update a table with specified filters
 */
void updateTable(string tableName, vector<string> filters){

}