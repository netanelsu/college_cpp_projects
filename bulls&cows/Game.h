#include<iostream>
#include"number.h"
using namespace std;
class game {
private:
	number *user, *computer;
	int Cows();
	int Bulls();
public:
	game();
	~game();
	game(const game&obj);
	void play();

};