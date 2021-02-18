#include "stadium.h"

void stadium::PrintStadium()
{
	cout << "stadium name: " << Name << endl;
	cout << "city: " << City << endl;
	cout << "capacity: " << Capacity << endl;
}

string stadium::GetSName()
{
	return this->Name;
}
