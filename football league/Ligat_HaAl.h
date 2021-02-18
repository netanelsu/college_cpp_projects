#include"game.h"
using namespace std;
class Ligat_HaAl
{
private:
	team** Teams;
	game** Games;
	worker** Workers;
	int workers_num;
	void AddFootballer();
	void AddReferee();
	void PrintMenu();
	int BiggerPoint(int[]);
public:
	Ligat_HaAl();
	~Ligat_HaAl();
	void Menu();
};

