#include "footballer.h"

footballer::footballer(const footballer &obj):worker(obj.FirstName,obj.LastName,obj.Id)
{
	TeamName = obj.TeamName;
	Goals = obj.Goals;
	const int Games = obj.Games;
	Position = obj.Position;
}

string footballer::GetId()
{
	return Id;
}

bool footballer::OutStanding()
{
	float percent;
	percent = Success();
	if (percent > 75) { return true; }
	else {
		return false;
	}
}

float footballer::Salary()
{
	float salary,x;
	x = Success();
	salary = 6500.00 + (x / 100) * 2000;
	return salary;
}

void footballer::PrintFootballer()
{
	Print();
	cout << "team: " << TeamName << endl;
	cout << "role:" << Position << endl;
	cout << "goals scorred: " << Goals << endl;
	cout << "success percent: " << Success()<<endl;
	cout << "salary: " << Salary() << endl;
}
