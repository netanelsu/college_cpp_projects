#include"digits.h"
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;
class number {
	friend class game;
private:
	digit num[4];
	bool CheckNum(int);
public:
	number();
	void UserNumber();
	void RandomNumber();
	int DigPlace(int);
	void print();
};
