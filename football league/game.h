#include<iostream>
#include<string>
#include "team.h"
#include"time.h"
class game{
private:
	Date* date;
	team* Team1;
	team* Team2;
	string Winner;
	int Goals1;
	int Goals2;
	referee** Referees;
	friend class Ligat_HaAl;
public:
	game( team&, team&, referee&, referee&, referee&);
	~game();
	game& operator +=(string);
	void PrintGame();
};

