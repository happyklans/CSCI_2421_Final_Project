/*
Benjamin Stanton
CSCI 2421

Description: driver program for the database 
*/

#include <iostream>
#include <fstream>
#include "Actor.h"
#include "Movie.h"
#include "Field.h"
#include "Functions.h"

using namespace std;

int main()
{
	BSTree<Actor, Field> Actors;

	BSTree<Movie, Field> Movies;	

	bool keep_going = true;

	Field input_verification;

	Field current_actor_sort_key = "name";

	Field current_movie_sort_key = "name";

	int menu_choice = 0;



	cout << "Welcome to the Academy Awards database" << endl << endl;

	while (keep_going)
	{
		cout << "Please select an option from the menu below:" << endl
			<< "1) Read in records from a file" << endl
			<< "2) Search for a record" << endl
			<< "3) Add a record manually" << endl
			<< "4) Modify a record" << endl
			<< "5) Delete a record" << endl
			<< "6) Sort the database" << endl
			<< "7) Print the data base to a file" << endl
			<< "8) Exit" << endl;

		cin >> input_verification;

		menu_choice = input_verification.stoi(); //using overloaded stoi

		switch (menu_choice)
		{
		case 1:
		{
			database::readFromFile(Actors, Movies);

			break;
		}
		case 2:
		{
			database::searchForItem(Actors, Movies, current_actor_sort_key, current_movie_sort_key);

			break;
		}
		case 3:
		{
			database::addItem(Actors, Movies, current_actor_sort_key, current_movie_sort_key);

			break;
		}
		case 4:
		{
			database::modifyItem(Actors, Movies, current_actor_sort_key, current_movie_sort_key);

			break;
		}
		case 5:
		{
			database::deleteItem(Actors, Movies, current_actor_sort_key, current_movie_sort_key);

			break;
		}
		case 6:
		{
			database::sortOnField(Actors, Movies, current_actor_sort_key, current_movie_sort_key);

			break;
		}
		case 7:
		{
			database::printToFile(Actors, Movies);

			break;
		}
		case 8:
		{
			keep_going = false;

			break;
		}
		default:
			cout << "Thats not a valid option. Please try again" << endl;

			break;
		}
	}
	
	return 0;
} 