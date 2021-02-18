#include "number.h"

bool number::CheckNum(int usernum)
{
	int val1, val2, val3, val4;
	if (usernum < 1234 || usernum>9876) {
		return false;
	}
	val1 = usernum % 10;
	usernum /= 10;
	val2 = usernum % 10;
	usernum /= 10;
	val3 = usernum % 10;
	usernum /= 10;
	val4 = usernum % 10;
	if (val1 == val2 || val1 == val3 || val1 == val4 || val2 == val3 || val2 == val4 || val3 == val4 || val1 == 0 || val2 == 0 || val3 == 0 || val4 == 0) {
		return false;
	}
	return true;
}

number::number()
{
	for (int i = 0; i < 4; i++) {
		num[i].value = 0;
	}
}

void number::UserNumber()
{
	int i = 3,val,usernum;
	bool flag;
	do {
		cin >> usernum;
		flag = CheckNum(usernum);
	} while (!flag);
	while (i>-1) {
		val = usernum % 10;
		num[i].value = val;
		i--;
		usernum/= 10;
		
	}
}

void number::RandomNumber()
{
	int i=0,j,count,val;
	srand(time(NULL));
	while (i < 4) {
		count = 0;
		val = rand() % 9 + 1;
		for (j = 0; j < i; j++) {
			if (val == num[j].value) {
				count++;
			}
		}
		if (count == 0&&val!=0) {
			num[i].value = val;
			i++;
		}
	}
}

int number::DigPlace(int index)
{
	if (index > 3 || index < 0) {
		return -1;
	}
	return num[index].value;
}

void number::print()
{
	int Number=0,i;
	for (i = 0; i < 4; i++) {
		Number += num[i].value;
		Number *= 10;
	}
	Number /= 10;
	cout << Number<<endl;
}
