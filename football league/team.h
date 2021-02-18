#include<iostream>
#include<string>
#include"stadium.h"
using namespace std;
class team{
private:
	string TeamName;
	stadium* Stadium;
	footballer** Squad;
	int Players;
	coach* Coach;
	manager* Manager;
	bool ManagerExist = false;
public:
	team(string teamname,const string names[], const string family[], string stadiums, const string ids[], string city);
	~team();
	void PrintTeam();
	bool CheckId(footballer);
	footballer** GetSquad();
	string GetStadiumName();
	int GetSize();
	string GetName();
	coach* GetCoach();
	manager* GetManager();
	team& operator+=(footballer&);
	team& operator+=(const coach&);
	team& operator+=(const manager&);
	footballer* GetPlayer(int);
};

