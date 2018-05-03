#include "Movie.h"



Movie::Movie() //takes no initializations
{
	Field Name = "";
	Field Year = "";
	Field Nominations = "";
	Field Rating = "";
	Field Duration = "";
	Field Genre1 = "";
	Field Genre2 = "";
	Field Release = "";
	Field Metacritic = "";
	Field Synopsis = "";
}

Movie::Movie(Field _Name, Field _Year, Field _Nominations, Field _Rating,
	Field _Duration, Field _Genre1, Field _Genre2, Field _Release,
	Field _Metacritic, Field _Synopsis)
{
	Name = _Name;

	Year = _Year;

	Nominations = _Nominations;

	Rating = _Rating;

	Duration = _Duration;

	Genre1 = _Genre1;

	Genre2 = _Genre2;

	Release = _Release;

	Metacritic = _Metacritic;

	Synopsis = _Synopsis;
}

void Movie::clear()
{
	Name = "";
	Year = "";
	Nominations = "";
	Rating = "";
	Duration = "";
	Genre1 = "";
	Genre2 = "";
	Release = "";
	Metacritic = "";
	Synopsis = "";
}

bool operator < (Movie _left, Movie _right)
{
	if (_left.Name < _right.Name)
	{
		return true;
	}
	else return false;
}

ifstream & operator >> (ifstream & in, Movie & _movie)
{
	in >> _movie.Name >> _movie.Year >> _movie.Nominations >> _movie.Rating >>
		_movie.Duration >> _movie.Genre1 >> _movie.Genre2 >> _movie.Release >>
		_movie.Metacritic >> _movie.Synopsis;

	return in;
}

ostream & operator << (ostream & out, Movie _movie)
{
	out << _movie.Name << endl << _movie.Year << endl << _movie.Nominations << endl << 
		_movie.Rating << endl << _movie.Duration << endl << _movie.Genre1 << endl
		<< _movie.Genre2 << endl << _movie.Release << endl << _movie.Metacritic 
		<< endl << _movie.Synopsis << endl;

	return out;
}

ofstream & operator << (ofstream & out, Movie _movie)
{
	out << _movie.Name << "," << _movie.Year << "," << _movie.Nominations << "," << _movie.Rating
		<< "," << _movie.Duration << "," << _movie.Genre1 << "," << _movie.Genre2 << "," <<
		_movie.Release << "," << _movie.Metacritic << "," << _movie.Synopsis << endl;

	return out;
}