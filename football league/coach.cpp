#include "coach.h"

float coach::Salary()
{
	return 4500.0 + 200 * Seniority + 500 * Championships;
}

bool coach::OutStanding()
{
	if (Championships > 1) { return true; }
	else { return false; }
}

void coach::PrintCoach()
{
	PrintWorker();
	cout << "team: " << TeamName << endl;
	cout << "championships: " << Championships << endl;
}

string coach::GetCFName()
{
	return FirstName;
}

string coach::GetCLName()
{
	return LastName;
}

bool coach::GetFormer()
{
	return FormerFootballer;
}
