#include "person.h"

string person::GetId()
{
	return Id;
}

person::person(const person &obj)
{
	FirstName = obj.FirstName;
	LastName = obj.LastName;
	Id = obj.Id;
}

void person::Print()
{
	cout << "name:" << FirstName << ' ' << LastName << endl << "id:" << Id << endl;
}
