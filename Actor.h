#ifndef ACTOR_H
#define ACTOR_H

#include "Field.h"
#include <iostream>

using namespace std;

class Actor
{
public:
	Actor();
	Actor(Field _year, Field _award, Field _winner, Field _name, Field _film);
	void set_year(Field _year) { Year = _year; }
	void set_award(Field _award) { Award = _award; }
	void set_winner(Field _winner) { Winner = _winner; }
	void set_name(Field _name) { Name = _name; }
	void set_film(Field _film) { Film = _film; }
	void clear();
	Field get_year() { return Year; }
	Field get_award() { return Award; }
	Field get_winner() { return Winner; }
	Field get_name() { return Name; }
	Field get_film() { return Film; }

	friend bool operator < (Actor _left, Actor _right);


	friend ifstream & operator >> (ifstream & in, Actor & _actor);

	friend ostream & operator << (ostream & out, Actor _actor);

	friend ofstream & operator << (ofstream & out, Actor _actor);


private:
	Field Year;
	Field Award;
	Field Winner;
	Field Name;
	Field Film;
};


#endif // !ACTOR_H