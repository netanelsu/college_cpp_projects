#include "referee.h"
int referee::Max_Mistakes = -1;
float referee::Salary()
{
	if (Mistakes == Max_Mistakes) {
		return 4500.00 + 30 * GamesM - 500;
	}
	else {
		return 4500.00 + 30 * GamesM;
	}
}

bool referee::OutStanding()
{
	if (Mistakes <= (Max_Mistakes / 2.0)) {
		return true;
	}
	else {
		return false;
	}
}

void referee::UpdateMis(int MoreMis)
{
	Mistakes += MoreMis;
	if (Mistakes > Max_Mistakes) {
		Max_Mistakes = Mistakes;
	}
}

void referee::PrintReferee()
{
	PrintWorker();
	cout <<"mistakes: "<< Mistakes<<endl;
	cout << "Games Manage: " << GamesM << endl;
}

string referee::GetLName()
{
	return LastName;
}

int referee::GetMistakes()
{
	return Mistakes;
}

int referee::GetMaxMis()
{
	return Max_Mistakes;
}

int referee::GetGames()
{
	return GamesM;
}

string referee::GetFName()
{
	return FirstName;
}
