/*
Benjamin Stanton
CSCI 2421 Final Project

Description: A file containing the declarations for all the menu functions, to make the main driver
			 cleaner and more readable
			 */

#include <iostream>
#include <fstream>
#include "BSTree.h"
#include "BSTree.hpp"
#include "Actor.h"
#include "Movie.h"
#include "Field.h"

using namespace std;

namespace database
{
	int databaseChoice();

	void readFromFile(BSTree<Actor, Field> & _actors, BSTree<Movie, Field> & _movies);

	void addItem(BSTree<Actor, Field> & _actors, BSTree<Movie, Field> & _movies, 
		Field current_actor_sort_key, Field current_movie_sort_key);

	void deleteItem(BSTree<Actor, Field> & _actors, BSTree<Movie, Field> & _movies,
		Field current_actor_sort_key, Field current_movie_sort_key);

	void modifyItem(BSTree<Actor, Field> & _actors, BSTree<Movie, Field> & _movies,
		Field current_actor_sort_key, Field current_movie_sort_key);

	void printToFile(BSTree<Actor, Field> & _actors, BSTree<Movie, Field> & _movies);

	void sortOnField(BSTree<Actor, Field> & _actors, BSTree<Movie, Field> & _movies,
		Field & current_actor_sort_key, Field & current_movie_sort_key);

	void searchForItem(BSTree<Actor, Field> & _actors, BSTree<Movie, Field> & _movies,
		Field current_actor_sort_key, Field current_movie_sort_key);

}



