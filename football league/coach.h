#include<iostream>
#include<string>
#include"footballer.h"
using namespace std; 
class coach:public worker{
private:
	string TeamName;
	bool FormerFootballer;
	int Championships;
public:
	coach(string first, string last, string id, string team) :worker(first, last, id), TeamName(team){
		//srand(time(NULL));
		Championships = rand() % Seniority + 1;
		int flag = rand() % 2;
		if (flag == 0) {
			FormerFootballer = false;
		}
		if (flag == 1) {
			FormerFootballer = true;
		}
	}
	~coach() {}
	float Salary();
	bool OutStanding();
	void PrintCoach();
	string GetCFName();
	string GetCLName();
	bool GetFormer();
};

