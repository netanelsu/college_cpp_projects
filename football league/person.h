#include<iostream>
#include<string>
using namespace std;
class person {
protected:
	string FirstName;
	string LastName;
	string Id;
	friend class team;
public:
	person(string first, string last, string id) :FirstName(first), LastName(last), Id(id) {};
	~person() {}
	string GetId();
	person(const person&);
	void Print();
	virtual bool OutStanding() = 0;
};