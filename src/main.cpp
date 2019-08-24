#include <string>
#include <vector>

#include <iostream>
#include "headers.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	/*
		hold the current path to a db or table
	 */

	vector<string> currentPath;
	currentPath.push_back(DB_DirPath);

	// the command(query) from keyboard
	string command;

	// process queries until "exit" command input form keyboard
	while (command.compare("exit") != 0)
	{
		cout << "DBMS>> ";
		
		// put the raw query string on command
		getline(cin, command);

		// get the query string parsed
		vector<string> parsedQuery = parseQuery(command);
		/*
			once parsed, know the main query and process based on it
		 */
		string mainQuery = parsedQuery[0];
		
		// process create commands
		if (mainQuery == "create")
		{
			if (parsedQuery[1] == "database")
			{
				// pass the name of the db from parsed query
				createDatabase(parsedQuery[2]);
			}
			else if(parsedQuery[1] == "table"){
				// pass the path of the db, name of the table and columns from the parsed query
				createTable(currentPath, parsedQuery[2], parsedQuery);
			}
			else {
				showErrorMessage();
			}
			
		}
		// process use comands
		else if (mainQuery == "use")
		{
			// add the database name to paths vector
			
			if(currentPath.size() == 1){
				currentPath.push_back(parsedQuery[1]);
			}
			else {
				 /*
					if already the current database is selected, pop it and add..
					the recent one
				  */
				currentPath.pop_back();
				currentPath.push_back(parsedQuery[1]);
			}
		}
		// process show commands
		else if (mainQuery == "show")
		{
			if(parsedQuery[1] == "databases" || parsedQuery[1] == "tables"){
				showDbsOrTables(parsedQuery[1], currentPath);
			}
			else {
				showErrorMessage();
			}
			
		}
		// process insert
		else if (mainQuery == "insert")
		{
		}
		// process select
		else if (mainQuery == "select")
		{
		}
		// process update
		else if (mainQuery == "update")
		{
		}
		// all other main queries
		else
		{
			if (mainQuery != "exit")
				showErrorMessage();
		}
	}
	// user exited
	cout << "Good bye!" << endl;
}