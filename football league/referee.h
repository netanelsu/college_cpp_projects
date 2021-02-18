
#include<iostream>
#include<string>
#include"coach.h"
class referee:public worker{
private:
	int Mistakes;
	int GamesM;
	static int Max_Mistakes;
public:
	referee(string first, string last, string id) :worker(first, last, id), Mistakes(0), GamesM(0) {}
	~referee() {}
	float Salary();
	bool OutStanding();
	void UpdateMis(int);
	void UpdateGames() {
		GamesM += 1;
	};
	void PrintReferee();
	string GetFName();
	string GetLName();
	int GetMistakes();
	int GetMaxMis();
	int GetGames();
};

