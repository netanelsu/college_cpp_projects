#include<iostream>
using namespace std;
class battleship {
private:
	int length;
	static int serial;
public:
	battleship();
	friend class game;
};