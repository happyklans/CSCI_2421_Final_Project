/*
Benjamin Stanton
CSCI 2421

Desctiption: movie class for holding the movie nominees
*/


#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <fstream>
#include "Field.h"

using namespace std;

class Movie
{
public:
	Movie();
	Movie(Field _Name, Field _Year,	Field _Nominations,	Field _Rating,
		Field _Duration, Field _Genre1, Field _Genre2,	Field _Release,
		Field _Metacritic,	Field _Synopsis);
	void set_name(Field _name) { Name = _name; }
	void set_year(Field _year) { Year = _year; }
	void set_nominations(Field _nominatons) { Nominations = _nominatons; }
	void set_rating(Field _rating) { Rating = _rating; }
	void set_duration(Field _duration) { Duration = _duration; }
	void set_genre1(Field _genre1) { Genre1 = _genre1; }
	void set_genre2(Field _genre2) { Genre2 = _genre2; }
	void set_release(Field _release) { Release = _release; }
	void set_metacritic(Field _metacritic) { Metacritic = _metacritic; }
	void set_synopsis(Field _synopsis) { Synopsis = _synopsis; }
	void clear();
	Field get_name() { return Name; }
	Field get_year() { return Year; }
	Field get_nominations() { return Nominations; }
	Field get_rating() { return Rating; }
	Field get_duration() { return Duration; }
	Field get_genre1() { return Genre1; }
	Field get_genre2() { return Genre2; }
	Field get_release() { return Release; }
	Field get_metacritic() { return Metacritic; }
	Field get_synopsis() { return Synopsis; }

	friend bool operator < (Movie _left, Movie _right);


	friend ifstream & operator >> (ifstream & in, Movie & _movie);

	friend ostream & operator << (ostream & out, Movie _movie);

	friend ofstream & operator << (ofstream & out, Movie _movie);

private:
	Field Name;
	Field Year;
	Field Nominations;
	Field Rating;
	Field Duration;
	Field Genre1;
	Field Genre2;
	Field Release;
	Field Metacritic;
	Field Synopsis;
};


#endif // !ACTOR_H