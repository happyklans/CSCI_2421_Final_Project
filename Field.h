/*
Benjamin Stanton
CSCI 2421

Description: class of string-type that is written specifically to read from csv files

Credit: inspiration and design taken from a class of the same name written by 
Dr. Julie Schneider, Red Rock Community College. 
 
*/

#ifndef FIELD_H
#define FIELD_H

#include <string>
#include <fstream>   
#include <iostream> 

using namespace std;

class Field : public string //field inherits from string, so field "is a" string
{
public:
	// constructors
	Field(); // default  constructor
	
	Field(string str); //copy constructor
	
	Field(const char* cStr); //copy constructor 

	friend istream& operator>>(istream& in, Field & field);

	friend ifstream& operator>>(ifstream& in, Field & field);

	int stoi(); //overloaded stoi function for additional exception tolerance

	//all private data fields's are inherited
};

#endif