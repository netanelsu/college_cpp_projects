#include<iostream>
#include<string>
#include"referee.h"
using namespace std;
class manager:public worker{
public:
	manager(string first, string last, string id):worker(first, last, id) {}
	~manager() {}
	float Salary();
	bool OutStanding();
};

