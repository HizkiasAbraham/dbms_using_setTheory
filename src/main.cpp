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
			cout << "create executed"<< endl;
		}
		// process use comands
		else if (mainQuery == "use")
		{
		}
		// process show commands
		else if (mainQuery == "show")
		{
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
				cout << "ERROR: Invalid query!" << endl;
		}
	}
	// user exited
	cout << "Good bye!" << endl;
}