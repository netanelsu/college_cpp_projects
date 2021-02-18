#include<iostream>
#include<string>
#include"worker.h"
using namespace std;
class footballer:public worker{
private:
	string TeamName;
	int Goals;
	const int Games = 8;
	string Position;
	friend class team;
public:
	footballer(string first, string last, string id, string team,int role) :worker(first, last, id), TeamName(team) {
		Goals = 0;
		 switch (role) {
		 case 0:
			 Position = "GoalKeeper";
			 break;
		 case 1:
			 Position = "Defender";
			 break;
		 case 2:
			 Position = "Back";
			 break;
		 case 3:
			 Position = "Midfielder";
			 break;
		 case 4:
			 Position = "Forward";
			 break;
		 default:
			 Position = "wrong";
			 break;
		 }
	}
	~footballer() {}
	footballer(const footballer&);
	string GetId();
	float Success(){ return float(Goals / 8.0) * 100; };
	bool OutStanding();
	void AddGoal() { Goals += 1; }
	float Salary();
	void PrintFootballer();
};

