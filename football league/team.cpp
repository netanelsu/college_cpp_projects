#include "team.h"

team::team(string teamname,const string names[],const string family[], string stadiums, const string ids[],string city) {
	int i;
	TeamName = teamname;
	Stadium = new stadium(stadiums, city);
	Squad = new footballer*[15];
	for (i = 0; i < 2; i++) {
		Squad[i] = new footballer(names[i], family[i], ids[i], TeamName, 0);
	}
	for (i = 2; i < 5; i++) {
		Squad[i] = new footballer(names[i], family[i], ids[i], TeamName, 1);
	}
	for (i = 5; i < 8; i++) {
		Squad[i] = new footballer(names[i], family[i], ids[i], TeamName, 2);
	}
	for (i = 8; i < 12; i++) {
		Squad[i] = new footballer(names[i], family[i], ids[i], TeamName, 3);
	}
	for (i = 12; i < 15; i++) {
		Squad[i] = new footballer(names[i], family[i], ids[i], TeamName, 4);
	}
	Players = 15;
	Coach = new coach(names[15], family[15], ids[15], TeamName);
	i++;
	Manager = new manager(names[16], family[16], ids[16]);
	ManagerExist = true;
}

team::~team()
{
	int i;
	delete Stadium;
	delete Manager;
	delete Coach;
	for (i = 0; i < Players; i++) {
		delete Squad[i];
	}
	delete[] Squad;
}

void team::PrintTeam()
{
	int i;
	cout << "team name: " << TeamName << endl;
	Stadium->PrintStadium();
	cout << "coach:" << endl;
	Coach->PrintCoach();
	cout << "manager:" << endl;
	Manager->PrintWorker();
	cout << "players:" << endl;
	for (i = 0; i < Players; i++) {
		Squad[i]->PrintFootballer();
	}
}

bool team::CheckId(footballer obj)
{
	for (int i = 0; i < Players; i++) {
		if (obj.Id == Squad[i]->Id) {
			return false;
		}
	}
	return true;
}

footballer** team::GetSquad()
{
	return Squad;
}

string team::GetStadiumName()
{
	return Stadium->GetSName();
}

int team::GetSize()
{
	return Players;
}

string team::GetName()
{
	return TeamName;
}

coach* team::GetCoach()
{
	return Coach;
}

manager* team::GetManager()
{
	return Manager;
}

team & team::operator+=(footballer& obj)
{
	int i;
	bool flag=true;
	for (i = 0; i < Players; i++) {
		if (Squad[i]->Id == obj.Id) {
			flag = false;
		}
	}
	if (flag) {
		footballer** temp;
		temp = new footballer*[Players + 1];
		for (i = 0; i < Players; i++) {
			temp[i] = Squad[i];
		}
		temp[i] = &obj;
		Squad = temp;
		Players += 1;
	}
	else {
		cout << "player already exist!!" << endl;
	}
	return *this;
}

team & team::operator+=(const coach &obj)
{
	if (Coach != NULL) {
		cout << "coach already exist" << endl;
	}
	else {
		Coach = new coach(obj);
	}
	return *this;
}

team & team::operator+=(const manager &obj)
{
	if (!ManagerExist) {
		Manager = new manager(obj);
		ManagerExist = true;
	}
	else {
		cout << "manager already exist" << endl;
	}
	return *this;
}

footballer * team::GetPlayer(int index)
{
	return Squad[index];
}

