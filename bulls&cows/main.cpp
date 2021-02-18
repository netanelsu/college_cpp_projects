#include"Game.h"
#include<iostream>
using namespace std;
int main() {
	cout << "wellcome to the game 'bulls and cows' in this game you'll try to guess a random 4 digits number" << endl;
	cout << "bull mean right number in right place (B) and cows mean right number in wrong place (C)" << endl;
	cout << "==================================================" << endl;
	cout << "please insert 4 digit number with 4 diffrence digits and no 0" << endl;
	game p1;
	p1.play();
	return 0;
}