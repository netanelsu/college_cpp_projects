#include "game.h"

game::game( team &team1,  team &team2, referee &ref1, referee &ref2, referee &ref3)
{
	int day, month,i;
	Winner = "tie";
	Goals1 = Goals2 = 0;
	//srand(time(NULL));
	date = new Date(rand()%28+1, rand()%12+1, 2019);
	Team1 = &team1;
	Team2 = &team2;
	Referees = new referee*[3];
	Referees[0] = &ref1;
	Referees[1] = &ref2;
	Referees[2] = &ref3;
}

game::~game()
{
	delete date;
	for (int i = 0; i < 3; i++) {
		Referees[i]->~referee();
	}
	delete[] Referees;
}

game & game::operator+=(string id)
{
	int i;
	for (i = 0; i < Team1->GetSize(); i++) {
		if (Team1->GetSquad()[i]->GetId() == id) {
			Team1->GetSquad()[i]->AddGoal();
			Goals1++;
		}
	}
	for (i = 0; i < Team2->GetSize(); i++) {
		if (Team2->GetSquad()[i]->GetId() == id) {
			Team2->GetSquad()[i]->AddGoal();
			Goals2++;
		}
	}
	if (Goals1 > Goals2) {
		Winner = Team1->GetName();
	}
	else if (Goals1 < Goals2) {
		Winner = Team2->GetName();
	}
	else {
		Winner = "tie";
	}
	return *this;
}

void game::PrintGame()
{
	cout << "date: ";
	date->PrintDate();
	cout << "team 1: " << endl << Team1->GetName() << endl;
	cout << "Coach: " << endl << Team1->GetCoach()->GetCFName()<<" "<< Team1->GetCoach()->GetCLName() << endl;
	cout << "team 2: " << endl << Team2->GetName()<<endl;
	cout << "Coach: " << endl << Team2->GetCoach()->GetCFName() << " " << Team2->GetCoach()->GetCLName() << endl<<endl;
	cout << "stadium: " << endl;
	cout<<Team1->GetStadiumName();
	cout << endl;
	cout << "referees:" << endl;
	cout << Referees[0]->GetFName()<< " " << Referees[0]->GetLName() << endl;
	cout << Referees[1]->GetFName()<< " " << Referees[1]->GetLName() << endl;
	cout << Referees[2]->GetFName()<< " " << Referees[2]->GetLName() << endl;
	cout << "resault:" << endl;
	cout << Goals1 << " - " << Goals2 << endl;
	cout << "winner: " << Winner << endl;
}
