#include "worker.h"

worker::worker(const worker &obj):person(obj.FirstName,obj.LastName,obj.Id)
{
	Seniority = obj.Seniority;
}

void worker::PrintWorker()
{
	person::Print();
	cout << "seniority: " << Seniority << endl;
	cout << "salary: " << Salary() << endl;
}
