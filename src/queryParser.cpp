#include "headers.h"
#include <iostream>

#include<set>

using std::vector;

// separates the strings by a space and returns the parsed

vector<string> parseQuery(string str) 
{ 
    vector<string> parsed;
   string word = ""; 
   for (auto x : str + " ") 
   {
       if (x == ' ') 
       { 
        //    cout << word << endl; 
           parsed.push_back(word);
           word = ""; 
       } 
       else
       { 
           word = word + x; 
       } 
   }  
//    cout << word << endl; 
    return parsed;
} 