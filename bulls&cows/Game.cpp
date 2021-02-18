#include "Game.h"

int game::Cows()
{
	int i, j, count = 0,val;
	bool flag;
	for (i = 0; i < 4; i++) {
		val=user->DigPlace(i);
		for (j = 0; j < 4; j++) {
			flag = computer->num[j].Compare(val);
			if (flag&&i != j) {
				count++;
			}
		}
	}
	return count;
}

int game::Bulls()
{
	int i, j, count = 0, val;
	bool flag;
	for (i = 0; i < 4; i++) {
		val = user->DigPlace(i);
		for (j = 0; j < 4; j++) {
			flag = computer->num[j].Compare(val);
			if (flag&&i == j) {
				count++;
			}
		}
	}
	return count;
}

game::game()
{
	user = new number;
	computer = new number;
	user->UserNumber();
	computer->RandomNumber();
}

game::~game()
{
	delete[] user;
	delete[] computer;
	cout << "im dctor" << endl;
}

game::game(const game & obj)
{
	user = obj.user;
	computer = obj.computer;

}

void game::play()
{
	char again = 'n';
	do {
	    int cows=0, bulls=0;
		computer->RandomNumber();
		if (again == 'y') {
			cout << "please insert 4 digit number with 4 diffrence digits and no 0" << endl;
			user->UserNumber();
		}
		
		cout << "guess||C||B" << endl;
		user->print();
		do {
			cows = Cows();
			bulls = Bulls();
			cout<< ' ' <<' '<<' '<<' '<<' '<<' '<<' '<< cows <<' '<<' '<< bulls << endl;
			if (bulls == 4) {
				cout << "**YOU WIN**" << endl;
			}
			else {
				user->UserNumber();
			}
		} while (bulls != 4);
		cout << "do you want to play again? Y|N" << endl;
		cin >> again;
		getchar();
	} while (again == 'y' || again == 'Y');
	


}
