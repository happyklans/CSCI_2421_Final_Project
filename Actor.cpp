/*
Benjamin Stanton
CSCI 2421

Description: implementation of the Actor class
*/

#include "Actor.h"

//default constructor
Actor::Actor()
{
	Year = "";

	Award = "" ;

	Winner = "";

	Name = "";

	Film = "";
}

Actor::Actor(Field _year, Field _award, Field _winner, Field _name, Field _film)
{
	Year = _year;

	Award = _award;

	Winner = _winner;

	Name = _name;

	Film = _film;
}

void Actor::clear()
{
	Year = "";

	Award = "";

	Winner = "";

	Name = "";

	Film = "";
}

bool operator < (Actor left, Actor right)
{
	if (left.get_name() < right.get_name())
	{
		return true;
	}
	else
	{
		return false;
	}
}

ifstream & operator >> (ifstream & in, Actor & _actor)
{
	in >> _actor.Year >> _actor.Award >> _actor.Winner >> _actor.Name >> _actor.Film;

	return in;
}

ostream & operator << (ostream & out, Actor _actor)
{
	out << _actor.Year << endl << _actor.Award << endl << _actor.Winner << endl 
		<< _actor.Name << endl << _actor.Film << endl;

	return out;
}

ofstream & operator << (ofstream & out, Actor _actor)
{
	out <<  _actor.Year << ',' << _actor.Award << ',' << _actor.Winner << ','
		<< _actor.Name << ',' << _actor.Film << endl;

	return out;
}
