#include "headers.h"
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/variant.hpp>
#include <iostream>

using namespace boost::filesystem;
using boost::variant;
using std::cout;
using std::endl;
using std::ios;
/*
    builds path object from path strings vector
 */
path buildPath(vector<string> pathVector)
{
    string currentPath = "";

    for (string pathName : pathVector)
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
void createDatabase(string dbName)
{
    path newDbPath = path(DB_DirPath + "/" + dbName);
    if (create_directory(newDbPath))
    {
        cout << "created database " << dbName << endl;
    }
    else
    {
        cout << "Query failed: unable to create database" << endl;
    }
}
/*
    shows list of databases or tables already created
 */
void showDbsOrTables(string entity, vector<string> currentPath)
{
    if (entity == "databases")
    {

        cout << "Databases" << endl;
        cout << "=========" << endl;
        /*
            iterate over the list of dir names in the root 
            folder
         */
        path rootPath = path(DB_DirPath);
        directory_iterator end_itr;

        for (directory_iterator itr(rootPath); itr != end_itr; ++itr)
        {
            if (is_directory(itr->path()))
            {
                cout << itr->path().filename() << endl;
            }
        }
    }
    else
    {
        cout << "Tables in " << currentPath[currentPath.size() - 1] << endl;
        cout << "================" << endl;
        /*
            iterate over the list of dirs in the current db  
            path
         */
        path dirPath = buildPath(currentPath);
        directory_iterator end_itr;

        for (directory_iterator itr(dirPath); itr != end_itr; ++itr)
        {
            if (is_directory(itr->path()))
            {
                cout << itr->path().filename() << endl;
            }
        }
    }
}
/*
    creates a table
    ================
     - a new sub directory inside a database directory
       and files for the each columns
 */
void createTable(vector<string> dbPath, string tableName, vector<string> columns)
{
    // now add the table name to the path vector
    dbPath.push_back(tableName);

    if (create_directory(buildPath(dbPath)))
    {
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
    else
    {
        cout << "Query failed: unable to create the table";
    }
}
/*
    returns the list of columns of a table
 */
vector<string> getColumnNames(vector<string> dbPath, string tableName)
{
    // columns to return
    vector<string> columns;
    dbPath.push_back(tableName);
    // path of table to iterate
    path tablePath = buildPath(dbPath);

    directory_iterator end_itr;

    for (directory_iterator itr(tablePath); itr != end_itr; ++itr)
    {
        if (is_regular_file(itr->path()))
        {
            columns.push_back(itr->path().filename().string());
        }
    }
}
/*
    inserts a data to specified columns in the params list
 */
void insertIntoTable(vector<string> dbPath, string tableName, vector<string> params)
{
    // get the names of the table
    vector<string> columnNames = getColumnNames(dbPath, tableName);
    // add the table name to the dpPath
    dbPath.push_back(tableName);
    // iterate over the columns and create file by each name
    for (int i = 0; i < columnNames.size(); i++)
    {
        // add the column name to dbPath so as to creat the file
        dbPath.push_back(columnNames[i]);
        // open with outfile stream in append mode(ios::app), insert the data and close
        ofstream outFile;
        outFile.open(buildPath(dbPath), ios::app);
        // because the first four params are query commands
        outFile << params[i + 4];
        outFile.close();
    }
}
/*
    query from a table
 */
void selectFrom(vector<string> dbPath, vector<string> query)
{
    if (query[1] == "all")
    {
        // get the table name from the query and append with the db path
        dbPath.push_back(query[3]);
        cout << "Fetch result" << endl;
        cout << "==============" << endl;
        vector<string> allColumns = getColumnNames(dbPath, query[3]);

        vector<vector<variant<int, string>>> table;

        for (string column : allColumns)
        {
            cout << column << "\t" << endl;
            // add the column ot db path
            dbPath.push_back(column);
            // infile reader for each column file
            ifstream inFile;
            inFile.open(buildPath(dbPath));
            // col string
            string col;
            inFile >> col;
            inFile.close();
            // add the column to the table vector
            table.push_back(buildColumn(col));
        }

        for (int i = 0; i < table.size(); i++)
        {
            for (int j = 0; j < table[i].size(); j++)
            {
                cout << table[i][j] << "\t";
            }
            
           cout << endl;
        }
    }
}
/*
    returns column as a vector of variants
 */
vector<variant<int, string>> buildColumn(string colfileValue)
{
    vector<variant<int, string>> column;
    variant<int, string> value;
    string word = "";
    for (auto ch : colfileValue)
    {
        if (ch == '\n')
        {
            value = word;
            column.push_back(value);
        }
        else
        {
            word += ch;
        }
    }

    return column;
}
/*
    delete from a table with specified filters
 */
void deleteFrom(string tableName, vector<string> filters)
{
}
/*
    update a table with specified filters
 */
void updateTable(string tableName, vector<string> filters)
{
}
/*
    show an error message to user
 */
void showErrorMessage()
{
    cout << "ERROR: invalid query!" << endl;
}