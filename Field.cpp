/*
Benjamin Stanton
CSCI 2421

Description: class of string-type that is written specifically to read from csv files

Credit: inspiration and design taken from a class of the same name written by
Dr. Julie Schneider, Red Rock Community College.

*/

#include "Field.h"
//due to the lack of private data fields, no arguements in the constructors are required
Field::Field(): string() {}

Field::Field(string str): string(str) {}

Field::Field(const char* cStr)	: string(cStr) {}

int Field::stoi()
{
	int num = 0;

	Field line = *this;

	for (unsigned int i = 0; i < line.size(); i++)
	{
		if (!isdigit(line[i]))
		{
			return 0;
		}
	}

	num = std::stoi(line);

	return num;
}

istream& operator>>(istream& is, Field & fld)
{
	if (is.peek() == '\n')
		is.ignore();
	getline(is, fld, '\n');
	return is;
}
ifstream& operator>>(ifstream& ifs, Field & fld)
{
	char i = 0;

	ifs.get(i);

	while (i != ',' && i != '\n')
	{
		if (ifs.eof())
		{
			return ifs;
		}
		
		fld += i;

		ifs.get(i);
	}

	return ifs;
}