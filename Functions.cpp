/*
Benjamin Stanton
CSCI 2421 Final Project

Description: A file containing the definitions for all the menu functions, to make 
			 the main driver cleaner and more readable
*/

#include "Functions.h"



int database::databaseChoice()
{
	int db = 0;

	Field db_choice;

	cout << "Choose one:" << endl
		<< "1) Actor" << endl
		<< "2) Movie" << endl;

	cin >> db_choice;

	db = db_choice.stoi(); //overloaded stoi

	return db;
}

void database::readFromFile(BSTree<Actor, Field> & _actors, BSTree<Movie, Field> & _movies)
{
	Field actor_file;

	Field movie_file;

	Field flush;

	Actor new_actor;

	Movie new_movie;

	ifstream inactorfile;

	ifstream inmoviefile;


	cout << "Enter the name of the file of movie professional awards: " << endl;

	cin >> actor_file;

	inactorfile.open(actor_file, ios::in);

	cout << "Enter the name of the file of movie awards: " << endl;

	cin >> movie_file;

	inmoviefile.open(movie_file, ios::in);

	getline(inactorfile, flush);

	getline(inmoviefile, flush);

	while (!inactorfile.eof())
	{
		inactorfile >> new_actor;

		_actors.addNode(new_actor.get_name(), new_actor);

		new_actor.clear();
	}

	while (!inmoviefile.eof())
	{
		inmoviefile >> new_movie;

		_movies.addNode(new_movie.get_name(), new_movie);

		new_movie.clear();
	}

	return;
}

void database::addItem(BSTree<Actor, Field> & _actors, BSTree<Movie, Field> & _movies, 
	Field current_actor_sort_key, Field current_movie_sort_key)
{
	Field in_data;

	switch (databaseChoice())
	{
	case 1:
	{
		Actor new_actor;

		cout << "Enter the year of the film the actor occured in:" << endl;

		cin >> in_data;

		new_actor.set_year(in_data);

		cout << "Enter the Award the actor was nominated for: " << endl;

		cin >> in_data;

		new_actor.set_award(in_data);

		cout << "Enter a 1 if the actor won the award, 0 otherwise:" << endl;

		cin >> in_data;

		new_actor.set_winner(in_data);

		cout << "Enter the name of the actor:" << endl;

		cin >> in_data;

		new_actor.set_name(in_data);

		cout << "Enter the title of the film " << in_data << " was nominated for:" << endl;

		cin >> in_data;

		new_actor.set_film(in_data);

		if (current_actor_sort_key == "name")
		{
			_actors.addNode(new_actor.get_name(), new_actor);
		}
		else
		{
			_actors.addNode(new_actor.get_year(), new_actor);
		}

		break;
	}
	case 2:
	{
		Movie new_movie;
		
		cout << "Enter the title of the movie: " << endl;

		cin >> in_data;

		new_movie.set_name(in_data);

		cout << "Enter the release year of the movie: " << endl;

		cin >> in_data;

		new_movie.set_year(in_data);

		cout << "Enter the number of awards the movie was nominated for: " << endl;

		cin >> in_data;

		new_movie.set_nominations(in_data);

		cout << "Enter the rating of the movie: " << endl;

		cin >> in_data;

		new_movie.set_rating(in_data);

		cout << "Enter the duration of the movie: " << endl;

		cin >> in_data;

		new_movie.set_duration(in_data);

		cout << "Enter the primary genre the movie falls into: " << endl;

		cin >> in_data;

		new_movie.set_genre1(in_data);

		cout << "Enter the secondary genre the movie falls into: " << endl;

		cin >> in_data;

		new_movie.set_genre2(in_data);

		cout << "Enter the month the movie was released: " << endl;

		cin >> in_data;

		new_movie.set_release(in_data);

		cout << "Enter the metacritic score of the movie: " << endl;

		cin >> in_data;

		new_movie.set_metacritic(in_data);

		cout << "Enter a synopsis of the film: " << endl;

		getline(cin, in_data);

		new_movie.set_synopsis(in_data);

		if (current_movie_sort_key == "year")
		{
			_movies.addNode(new_movie.get_year(), new_movie);
		}
		else if (current_movie_sort_key == "title")
		{
			_movies.addNode(new_movie.get_name(), new_movie);
		}
		else if (current_movie_sort_key == "duration")
		{
			_movies.addNode(new_movie.get_duration(), new_movie);
		}
		else if (current_movie_sort_key == "metacritic score")
		{
			_movies.addNode(new_movie.get_metacritic(), new_movie);
		}
		else if (current_movie_sort_key == "nominations")
		{
			_movies.addNode(new_movie.get_nominations(), new_movie);
		}
		else if (current_movie_sort_key == "rating")
		{
			_movies.addNode(new_movie.get_rating(), new_movie);
		}
		else
		{
			_movies.addNode(new_movie.get_name(), new_movie);
		}

		break;
	}
	default:
		cout << "Thats not a valid option. Returning to main menu" << endl;

		break;
	}
}

void database::deleteItem(BSTree<Actor, Field> & _actors, BSTree<Movie, Field> & _movies,
	Field current_actor_sort_key, Field current_movie_sort_key)
{
	switch (databaseChoice())
	{
	case 1:
	{		
		Field key;
		
		cout << "Enter the " << current_actor_sort_key << " of the actor record you want to delete:" << endl;

		cin >> key;

		_actors.deleteNode(key);

		break;
	}
	case 2:
	{
		Field key;

		cout << "Enter the " << current_movie_sort_key << " of the movie record you want to delete: " << endl;

		cin >> key;

		_movies.deleteNode(key);

		break;
	}
	default:
	{
		cout << "thats not a valid option." << endl;
		break;
	}
	}

	return;
}

void database::modifyItem(BSTree<Actor, Field> & _actors, BSTree<Movie, Field> & _movies,
	Field current_actor_sort_key, Field current_movie_sort_key)
{
	switch (databaseChoice())
	{
	case 1:
	{
		int fieldChoice = 0;

		Field actor;

		Field change;

		Node<Actor, Field> * record;

		cout << "Enter the " << current_actor_sort_key << " of the actor record you would like to modify:" << endl;

		cin >> actor;

		record = _actors.findNode(actor);

		if (record == nullptr)
		{
			cout << "Record not found" << endl;

			return;
		}

		cout << "Which field would you like to modify:" << endl
			<< "1) Name" << endl
			<< "2) Year" << endl
			<< "3) Award" << endl
			<< "4) Winner" << endl
			<< "5) Film" << endl;

		cin >> change;

		fieldChoice = change.stoi();

		switch (fieldChoice)
		{
		case 1:
		{
			cout << "Enter the new name:" << endl;

			cin >> change;

			record->Data().set_name(change);

			break;
		}
		case 2:
		{
			cout << "Enter the new year:" << endl;

			cin >> change;

			record->Data().set_year(change);

			break;
		}
		case 3:
		{
			cout << "Enter the new award:" << endl;

			cin >> change;

			record->Data().set_award(change);

			break;
		}
		case 4:
		{
			cout << "Enter the new winner status" << endl;

			cin >> change;

			record->Data().set_winner(change);

			break;
		}
		case 5:
		{
			cout << "Enter the new film title" << endl;

			cin >> change;

			record->Data().set_film(change);

			break;
		}
		default:
			cout << "Thats not a valid option";

			break;
		}


	}
	case 2:
	{
		int fieldChoice = 0;

		Field movie;

		Field change;

		Node<Movie, Field> * record;

		cout << "Enter the " << current_movie_sort_key << " of the movie record you would like to modify" << endl;

		cin >> movie;

		record = _movies.findNode(movie);

		if (record == nullptr)
		{
			cout << "Record not found" << endl;

			return;
		}

		cout << "Which field would you like to modify:" << endl
			<< "1) Title" << endl
			<< "2) Year" << endl
			<< "3) Nominations" << endl
			<< "4) Rating" << endl
			<< "5) Duration" << endl
			<< "6) Primary Genre" << endl
			<< "7) Secondary Genre" << endl
			<< "8) Release month" << endl
			<< "9) Metacritic" << endl
			<< "10) Synopsis" << endl;

		cin >> change;

		fieldChoice = change.stoi(); //pverloaded stoi

		switch (fieldChoice)
		{
		case 1:
		{
			cout << "Enter the new title:" << endl;

			cin >> change;

			record->Data().set_name(change);

			break;
		}
		case 2:
		{
			cout << "Enter the new year:" << endl;

			cin >> change;

			record->Data().set_year(change);

			break;
		}
		case 3:
		{
			cout << "Enter the new number of nominations" << endl;

			cin >> change;

			record->Data().set_nominations(change);

			break;
		}
		case 4:
		{
			cout << "Enter the new rating:" << endl;

			cin >> change;

			record->Data().set_rating(change);

			break;
		}
		case 5:
		{
			cout << "Enter the new duration: " << endl;

			cin >> change;

			record->Data().set_duration(change);

			break;
		}
		case 6:
		{
			cout << "Enter the new primary genre:" << endl;

			cin >> change;

			record->Data().set_genre1(change);

			break;
		}
		case 7:
		{
			cout << "Enter the new secondary genre: " << endl;

			cin >> change;

			record->Data().set_genre2(change);

			break;
		}
		case 8:
		{
			cout << "Enter that new release month: " << endl;

			cin >> change;

			record->Data().set_release(change);

			break;
		}
		case 9:
		{
			cout << "Enter the new metacritic score:" << endl;

			cin >> change;

			record->Data().set_metacritic(change);

			break;
		}
		case 10:
		{
			cout << "Enter the new synopsis:" << endl;

			cin >> change;

			record->Data().set_synopsis(change);

			break;
		}
		default:
		{
			cout << "thats not a valid option." << endl;
			break;
		}
		}

	}
	default:
	{
		cout << "thats not a valid option." << endl;
		break;
	}
	}
}

void database::printToFile(BSTree<Actor, Field> & _actors, BSTree<Movie, Field> & _movies)
{
	ofstream outactorfile;

	ofstream outmoviefile;

	outactorfile.open("actor-actress-output.csv", ios::out);

	outmoviefile.open("pictures-output.csv", ios::out);

	_actors.printToFileInorder(outactorfile);

	_movies.printToFileInorder(outmoviefile);

	return;
}

void database::sortOnField(BSTree<Actor, Field> & _actors, BSTree<Movie, Field> & _movies,
	Field & current_actor_sort_key, Field & current_movie_sort_key)
{
	Field sort_param_verify;

	int sort_param = 0;

	switch (databaseChoice())
	{
	case 1:
	{
		cout << "Choose a sortable field to sort the database on:" << endl
			<< "1) name" << endl
			<< "2) year" << endl;
		
		cin >> sort_param_verify;

		sort_param = sort_param_verify.stoi(); //overloaded stoi

		switch (sort_param)
		{
		case 1:
		{
			_actors.reorder(_actors.Root()->Data().get_name());

			current_actor_sort_key = "name";

			break;
		}
		case 2:
		{
			_actors.reorder(_actors.Root()->Data().get_year());

			current_actor_sort_key = "year";

			break;
		}
		default:
			break;
		}
	}
	case 2:
	{
		cout << "Choose a sortable field to sort the database on:" << endl
			<< "1) title" << endl
			<< "2) year" << endl
			<< "3) duration" << endl
			<< "4) Metacritic score" << endl
			<< "5) rating" << endl;

		cin >> sort_param_verify;

		sort_param = sort_param_verify.stoi();

		switch (sort_param)
		{
		case 1:
		{
			_movies.reorder(_movies.Root()->Data().get_name());

			current_movie_sort_key = "title";

			break;
		}
		case 2:
		{
			_movies.reorder(_movies.Root()->Data().get_year());

			current_movie_sort_key = "year";

			break;
		}
		case 3:
		{
			_movies.reorder(_movies.Root()->Data().get_duration());

			current_movie_sort_key = "duration";

			break;
		}
		case 4:
		{
			_movies.reorder(_movies.Root()->Data().get_metacritic());

			current_movie_sort_key = "metacritic score";

			break;
		}
		case 5:
		{
			_movies.reorder(_movies.Root()->Data().get_rating());

			current_movie_sort_key = "rating";

			break;
		}
		default:
		{
			cout << "thats not a valid option." << endl;
			break;
		}
		}
	}
	default:
	{
		cout << "thats not a valid option." << endl;
		break;
	}
	}
}

void database::searchForItem(BSTree<Actor, Field> & _actors, BSTree<Movie, Field> & _movies,
	Field current_actor_sort_key, Field current_movie_sort_key)
{
	Field searchParam;

	switch (databaseChoice())
	{
	case 1:
	{
		Node<Actor, Field> * record;

		cout << "Enter the " << current_actor_sort_key << "of the actor you wish to find:" << endl;

		cin >> searchParam;

		record = _actors.findNode(searchParam);

		if (record != nullptr)
		{
			cout << record->Data();
		}
		else
		{
			cout << "Record not found." << endl;
		}

		break;
	}
	case 2:
	{
		Node<Movie, Field> * record;

		cout << "Enter the " << current_movie_sort_key << " of the movie you would like to find:" << endl;

		cin >> searchParam;

		record = _movies.findNode(searchParam); 
		
		if (record != nullptr)
		{ 
			cout << record->Data();
		}
		else
		{
			cout << "Record not found." << endl;
		}

		break;
	}
	}
}

