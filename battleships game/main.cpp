#include<iostream>
#include"game.h"
int main() {
	int Battleships;
	cout << "against how many battleships you want to play?(1-5)... *every other number equal to 1*" << endl;
	cin >> Battleships;
	game p1(Battleships);
	p1.play();
}