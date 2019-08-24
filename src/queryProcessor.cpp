#include "headers.h"
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <iostream>

using namespace boost::filesystem;
using std::cout;
using std::endl;
/*
    builds path object from path strings vector
 */
path buildPath(vector<string> pathVector){
    string currentPath = "";

    for (string pathName: pathVector)
    {
        currentPath += "/" + pathName;
    }
    
    return path(currentPath);
}

/*
    creates database
    =================
     - a new directory inside the root directory ${DB_DirPath} for 
       database files
 */
void createDatabase(string dbName){
    path newDbPath = path(DB_DirPath + "/" + dbName);
    if (create_directory(newDbPath))
    {
        cout << "created database "<< dbName << endl;
    }
    else {
        cout << "Query failed: unable to create databse" << endl;
    }
    
}
/*
    shows list of databases or tables already created
 */
void showDbsOrTables(string entity, vector<string> currentPath){
    if(entity == "databases"){

        cout << "Databases" << endl;
        cout << "=========" << endl;
        /*
            iterate over the list of dir names in the current root 
            folder
         */
    }
    else {
        cout << "Tables in " << currentPath[currentPath.size() - 1] << endl;
        cout << "================" << endl;
        /*
            iterate over the list of dirs in the current db  
            path
         */ 
    }
}
/*
    creates a table
    ================
     - a new sub directory inside a database directory
       and files for the each columns
 */
void createTable(vector<string> dbPath, string tableName, vector<string> columns){
    // now add the table name to the path vector
    dbPath.push_back(tableName);
    
    if(create_directory(buildPath(dbPath))){
         /*
             Now create the files with each column name
             passed the parsed query where the first 2 are main query operations
          */
    
        for (int i = 2; i < columns.size(); i++)
        {
            // add the name of the path to the full db path
            dbPath.push_back(columns[i]);
            ofstream ofs;
            // creates an empty file and then close
            ofs.open(buildPath(dbPath));
            ofs.close();
            // now clear the last column name from db path
            dbPath.pop_back();
        }
        
    }
    else {
        cout << "Query failed: unable to create the table";
    }
}
/*
    returns the list of columns of a table
 */
vector<string> getColumnNames(vector<string> dbPath, string tableName){
    // columns to return
    vector<string> columns;
    dbPath.push_back(tableName);
    // path of table to iterate
    path tablePath = buildPath(dbPath);

    directory_iterator end_itr;

    for(directory_iterator itr(tablePath); itr != end_itr; ++itr){
      if(is_regular_file(itr->path())){
          columns.push_back(itr->path().filename().string());
      }
    }
}
/*
    inserts a data to specified columns in the params list
 */
void insertIntoTable(vector<string> dbPath, string tableName, vector<string> params){
    // get the names of the table
    vector<string> columnNames = getColumnNames(dbPath, tableName);

    for (int i = 0; i < columnNames.size(); i++)
    {
        
    }
    

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
/*
    show an error message to user
 */
void showErrorMessage(){
    cout << "ERROR: invalid query!" << endl;
}