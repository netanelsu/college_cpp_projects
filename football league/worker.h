#include<iostream>
#include "person.h"
#include<time.h>
using namespace std;
class worker :public person {
protected:
	int Seniority;
	friend class Ligat_HaAl;
public:
	worker(string first, string last, string id) :person(first, last, id){
		//srand(100);
		Seniority = rand() % 20 + 1;
	}
	~worker() {}
	worker(const worker&);
	virtual float Salary()=0;
	void PrintWorker();
};
