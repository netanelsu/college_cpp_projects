#include "game.h"
int game::cells = 0;
void game::ClearBoard()
{
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			board[i][j] = '_';
		}
	}
}
bool game::CheckSequence(int size,int base, int shift,int direction)
{
	int i;
	if (direction == horizonal) {
		if(shift+size==10){
			for (i = (shift-1); i < (shift + size); i++) {
				if (board[base][i] == 'S') {
					return false;
				}
			}
		}
		if (shift==0) {
			for (i = shift; i < (shift + size+1); i++) {
				if (board[base][i] == 'S') {
					return false;
				}
			}
		}
		if (shift!=0&&(shift+size)<10) {
			for (i = (shift-1); i < (shift + size+1); i++) {
				if (board[base][i] == 'S') {
					return false;
				}
			}
		}
		return true;
	}
	if (direction == vertical) {
		if (shift + size == 10) {
			for (i = (shift - 1); i < (shift + size); i++) {
				if (board[i][base] == 'S') {
					return false;
				}
			}
		}
		if (shift == 0) {
			for (i = shift; i <(shift + size + 1); i++) {
				if (board[i][base] == 'S') {
					return false;
				}
			}
		}
		if (shift != 0 && (shift + size) < 10) {
			for (i = (shift - 1); i < (shift + size + 1); i++) {
				if (board[i][base] == 'S') {
					return false;
				}
			}
		}
		return true;
	}
}
bool game::CheckPlace(int size, int longitude, int latitude, int direction)
{
	int i;
	bool flag;
	if (direction == horizonal) {
		if ((longitude + size) > 10) {
			return false;
		}
		if (latitude == 0) {
			for (i = 0; i < 2; i++) {
				flag = CheckSequence(size, (latitude + i), longitude, direction);
				if (!flag) {
					return false;
				}
			}
		}
		if (latitude == 9) {
			for (i = 0; i < 2; i++) {
				flag = CheckSequence(size, (latitude - i), longitude, direction);
				if (!flag) {
					return false;
				}
			}
		}
		if (latitude != 0 && latitude != 9) {
			for (i = 0; i < 3; i++) {
				flag = CheckSequence(size, (latitude - 1 + i), longitude, direction);
				if (flag == false) {
					return false;
				}
			}
		}
		return true;
	}
	if (direction == vertical) {
		if ((latitude + size) > 10) {
			return false;
		}
		if (longitude == 0) {
			for (i = 0; i < 2; i++) {
				flag = CheckSequence(size, longitude + i, latitude, direction);
				if (!flag) {
					return false;
				}
			}
		}
		if (longitude == 9){
			for (i = 0; i < 2; i++) {
				flag=CheckSequence(size,longitude-i,latitude,direction);
					if (!flag) {
						return false;
				}
			}
		}
		if (longitude != 0 && longitude != 9) {
			for (i = 0; i < 3; i++) {
				flag = CheckSequence(size, longitude - 1 + i, latitude, direction);
				if (flag == false) {
					return false;
				}
			}
		}
	}
}
void game::BuildBoard()
{
	int i, j,direction,longitude,latitude;
	bool flag;
	ClearBoard();
	srand(time(NULL));
	for (i = 0; i < battleships; i++) {
		do {
			direction = rand() % 2;
			longitude = rand() % 10;
			latitude = rand() % 10;
			flag = CheckPlace(navy[i].length, longitude, latitude,direction);
		} while (!flag);
		cells += navy[i].length;
		if (direction == horizonal) {
			for (j = longitude; j < longitude+navy[i].length; j++) {
				board[latitude][j] = 'S';
			}
		}
		if (direction == vertical) {
			for (j = latitude; j < latitude+navy[i].length; j++) {
				board[j][longitude] = 'S';
			}
		}
	}
}
bool game::CheckHit(int latitude, char longitude)
{
	latitude -= 1;
	if (longitude >= 'a'&&longitude <= 'j') {
		longitude -= 32;
	}
	switch (longitude) {
	case 'A':
		if (board[latitude][0] == 'X' || board[latitude][0] == '@') {
			cout << "you already choose this location" << endl;
			return false;
		}
		if (board[latitude][0] == '_') {
			board[latitude][0] = 'X';
			return false;
		}
		if (board[latitude][0] == 'S') {
			board[latitude][0] = '@';
			cout << "**Hit**" << endl;
			return true;
		}
		break;
	 case 'B':
		if (board[latitude][1] == 'X' || board[latitude][1] == '@') {
			cout << "you already choose this location" << endl;
			return false;
		}
		if (board[latitude][1] == '_') {
			board[latitude][1] = 'X';
			return false;
		}
		if (board[latitude][1] == 'S') {
			board[latitude][1] = '@';
			cout << "**Hit**" << endl;
			return true;
		}
		break;
     case 'C':
	    if (board[latitude][2] == 'X' || board[latitude][2] == '@') {
		cout << "you already choose this location" << endl;
		return false;
	}
		if (board[latitude][2] == '_') {
		board[latitude][2] = 'X';
		return false;
	}
		if (board[latitude][2] == 'S') {
		board[latitude][2] = '@';
		cout << "**Hit**" << endl;
		return true;
	}
		break;
	 case 'D':
		if (board[latitude][3] == 'X' || board[latitude][3] == '@') {
			cout << "you already choose this location" << endl;
			return false;
		}
		if (board[latitude][3] == '_') {
			board[latitude][3] = 'X';
			return false;
		}
		if (board[latitude][3] == 'S') {
			board[latitude][3] = '@';
			cout << "**Hit**" << endl;
			return true;
		}
		break;
	 case 'E':
		 if (board[latitude][4] == 'X' || board[latitude][4] == '@') {
			 cout << "you already choose this location" << endl;
			 return false;
		 }
		 if (board[latitude][4] == '_') {
			 board[latitude][4] = 'X';
			 return false;
		 }
		 if (board[latitude][4] == 'S') {
			 board[latitude][4] = '@';
			 cout << "**Hit**" << endl;
			 return true;
		 }
		 break;
	 case 'F':
		 if (board[latitude][5] == 'X' || board[latitude][5] == '@') {
			 cout << "you already choose this location" << endl;
			 return false;
		 }
		 if (board[latitude][5] == '_') {
			 board[latitude][5] = 'X';
			 return false;
		 }
		 if (board[latitude][5] == 'S') {
			 board[latitude][5] = '@';
			 cout << "**Hit**" << endl;
			 return true;
		 }
		 break;
	 case 'G':
		 if (board[latitude][6] == 'X' || board[latitude][6] == '@') {
			 cout << "you already choose this location" << endl;
			 return false;
		 }
		 if (board[latitude][6] == '_') {
			 board[latitude][6] = 'X';
			 return false;
		 }
		 if (board[latitude][6] == 'S') {
			 board[latitude][6] = '@';
			 cout << "**Hit**" << endl;
			 return true;
		 }
		 break;
	 case 'H':
		 if (board[latitude][7] == 'X' || board[latitude][7] == '@') {
			 cout << "you already choose this location" << endl;
			 return false;
		 }
		 if (board[latitude][7] == '_') {
			 board[latitude][7] = 'X';
			 return false;
		 }
		 if (board[latitude][7] == 'S') {
			 board[latitude][7] = '@';
			 cout << "**Hit**" << endl;
			 return true;
		 }
		 break;
	 case 'I':
		 if (board[latitude][8] == 'X' || board[latitude][8] == '@') {
			 cout << "you already choose this location" << endl;
			 return false;
		 }
		 if (board[latitude][8] == '_') {
			 board[latitude][8] = 'X';
			 return false;
		 }
		 if (board[latitude][8] == 'S') {
			 board[latitude][8] = '@';
			 cout << "**Hit**" << endl;
			 return true;
		 }
		 break;
	 case 'J':
		 if (board[latitude][9] == 'X' || board[latitude][9] == '@') {
			 cout << "you already choose this location" << endl;
			 return false;
		 }
		 if (board[latitude][9] == '_') {
			 board[latitude][9] = 'X';
			 return false;
		 }
		 if (board[latitude][9] == 'S') {
			 board[latitude][9] = '@';
			 cout << "**Hit**" << endl;
			 return true;
		 }
		 break;
	 default:
		 cout << "wrong input" << endl;
		 exit(1);
		 break;
	}
}
bool game::CheckSunk(int latitude, char longi)
{
	int i, j,longitude;
	latitude -= 1;
	if (longi == 'a' || longi == 'A') {
		longitude = 0;
	}
	if (longi == 'b' || longi == 'B') {
		longitude = 1;
	}
	if (longi == 'c' || longi == 'C') {
		longitude = 2;
	}
	if (longi == 'd' || longi == 'D') {
		longitude = 3;
	}
	if (longi == 'e' || longi == 'E') {
		longitude = 4;
	}
	if (longi == 'f' || longi == 'F') {
		longitude = 5;
	}
	if (longi == 'g' || longi == 'G') {
		longitude = 6;
	}
	if (longi == 'h' || longi == 'H') {
		longitude = 7;
	}
	if (longi == 'i' || longi == 'I') {
		longitude = 8;
	}
	if (longi == 'j' || longi == 'J') {
		longitude = 9;
	}
	for (i = latitude; i < 10 && board[i][longitude] != '_'; i++) {
		if (board[i][longitude] == 'S') {
			return false;
		}
	}
	for (i = latitude; i >0 && board[i][longitude] != '_'; i--) {
		if (board[i][longitude] == 'S') {
			return false;

		}
	}
	for (i = longitude; i < 10 && board[latitude][i] != '_'; i++) {
		if (board[latitude][i] == 'S') {
			return false;
		}
	}
	for (i = longitude; i >0 && board[latitude][i] != '_'; i--) {
		if (board[latitude][i] == 'S') {
			return false;
		}
	}
	return true;
}
void game::PrintOriginalBoard()
{
	int i, j;
	cout << "   " << "A  B  C  D  E  F  G  H  I  J"<< endl;
	for (i = 1; i < 10; i++) {
		cout << i<<"  ";
		for (j = 0; j < 10; j++) {
			cout << board[i - 1][j]<<"  ";
		}
		cout << endl;
	}
	cout << "10"<<" ";
	for (j = 0; j < 10; j++) {
		cout << board[9][j] << "  ";
	}
	cout << endl;
}
void game::play()
{
	int latitude,count=0;
	char longitude,x;
	bool flag,flag2;
	BuildBoard();
	cout << "do you want to see the original board before we start?(y/n)" << endl;
	cin >> x;
	if (x == 'Y' || x == 'y') {
		PrintOriginalBoard();
	}
	do {
		cout << "enter your guess latitiude(1-10) and longitude(A-J)...enter 00 to exit" << endl;
		cin >> latitude >> longitude;
		if (latitude == 0 && longitude == '0') { 
			exit (1); 
		}
		flag=CheckHit(latitude, longitude);
		PrintBoard();
		if (flag) {
			flag2 = CheckSunk(latitude, longitude);
			if (flag2) {
				cout << "**battleship sunk**" << endl;;
				count++;
			}
		}
	} while (count < battleships);
	if (count == battleships) {
		cout << "***YOU WIN**" << endl;
	}
}
game::game(int ships)
{
	if (ships <=5 && ships>1) {
		battleships = ships;
		navy = new battleship[ships];
	}
	else {
		battleships = 1;
		navy = new battleship;
	}
	for (int i = 0; i < battleships; i++) {
		cells += navy[i].length;
	}
}

game::~game()
{
	delete[]navy;
	cout << "im destractor" << endl;
}

void game::PrintBoard()
{
	int i, j;
	cout << "   " << "A  B  C  D  E  F  G  H  I  J" << endl;
	for (i = 1; i < 10; i++) {
		cout << i << "  ";
		for (j = 0; j < 10; j++) {
			if (board[i - 1][j] != 'S') {
				cout << board[i - 1][j] << "  ";
			}
			else {
				cout << '_' << "  ";
			}
		}
		cout << endl;
	}
	cout << "10" << " ";
	for (j = 0; j < 10; j++) {
		if (board[9][j] != 'S') {
			cout << board[9][j] << "  ";
		}
		else {
			cout << '_' << "  ";
		}
	}
	cout << endl;
}
