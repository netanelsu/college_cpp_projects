#include<time.h>
#include"battleship.h"
#include<iostream>
using namespace std;
enum direct { horizonal, vertical };
class game {
private: 
	char board[10][10];
	int battleships;
	battleship *navy;
	static int cells;
	void ClearBoard();
	bool CheckSequence(int, int,int,int);
	bool CheckPlace(int,int,int,int);
	void BuildBoard();
	bool CheckHit(int,char);
	bool CheckSunk(int, char);
public:
	game(int);
	~game();
	void PrintBoard();
	void PrintOriginalBoard();
	void play();
};
