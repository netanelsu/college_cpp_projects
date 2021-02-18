#include "Ligat_HaAl.h"

void Ligat_HaAl::AddFootballer()
{
	string team, Fname, Lname, id;
	int role,i,j=0;
	bool flag=false;
	cout << "insert team name" << endl;
	getchar();
	getline(cin,team);
	cout << "insert player first name last name id and role(0-goalkeeper,1-defender,2-back,3-midfielder,4-forward)" << endl;
	getline(cin, Fname);
	getline(cin, Lname);
	getline(cin, id);
	do {
		cin >> role;
		if (role < 0 || role>5) {
			cout << "wrong role, choose again" << endl;
		}
	} while (role < 0 || role>5);
	footballer* player;
	player = new footballer(Fname, Lname, id, team, role);
	worker** temp;
	temp = Workers;
	Workers = new worker*[workers_num + 1];
	for (i = 0; i < 5; i++) {
		if (Teams[i]->GetName() == team) {
			*Teams[i] += *player;
			flag = true;
		}
	}
	if (!flag) {
		cout << "wrong team name" << endl;
	}
	for (i = 0; i < workers_num; i++) {
		Workers[i] = temp[i];
	}
	Workers[i] = player;
	workers_num++;
}

void Ligat_HaAl::AddReferee()
{
	string Fname, Lname, id;
	int i, count = 0;
	cout << "insert player first name last name and id"<< endl;
	getchar();
	getline(cin, Fname);
	getline(cin, Lname);
	getline(cin, id);
	for (i = 0; i < workers_num; i++) {
		if (Workers[i]->GetId() == id) {
			cout << "referee already exist" << endl;
			exit(1);
		}
	}
	worker** temp;
	temp = new worker*[workers_num + 1];
	for (i = 0; i < workers_num; i++) {
		temp[i] = Workers[i];
	}
	referee* Referee;
	Referee=new referee(Fname, Lname, id);
	temp[i] = Referee;
	Workers = temp;
	workers_num++;
}

void Ligat_HaAl::PrintMenu()
{
	cout << "Ligat HaAl menu" << endl;
	cout << "1-add player" << endl << "2-add referee" << endl << "3-print team" << endl << "4-print referee" << endl;
	cout << "5-print future game" << endl << "6-print worker salary" << endl << "7-add goal" << endl << "8-add judgment errors" << endl;
	cout << "9-print outstanding people" <<endl<< "10-print table" << endl << "11-Print footballer details with smallest salary" << endl << "12-exit" << endl;
}

int Ligat_HaAl::BiggerPoint(int points[])
{
	int i,bigger=0,index;
	for (i = 0; i < 5; i++) {
		if (points[i] > bigger) {
			bigger = points[i];
			index = i;
		}
	}
	return index;
}

Ligat_HaAl::Ligat_HaAl()
{
	string names[17] = { "eyal","omer","rotem","tal","ben","netanel","gargir","shay","ella","tamar","ruth","dogi","shiran","shahar","yoni","maayan","gal" };
	string family[17] = { "cohen","levi","israeli","messi","ronaldo","melikson","barda","buzaglo","ogu","vered","shwartz","drogba","harush","sahar","zehavi","ben haim","feldman" };
	string teams[5] = { "hapoel","beitar","maccabi","fc sami","fc shimon" };
	string city[5] = { "beer sheva","tlv","haifa","jerusalem","netanya" };
	string stadiums[5] = { "terner","blumfield","teddi","sami ofer","vasermil" };
	string referees[8] = { "alon","yefet","orel","grinfeld","eli","hakmon","erez","pappir" };
	string refereeid[4] = { "100","101","102","103" };
	string ids[17] = { "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17" };
	string ids2[17] = { "18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34" };
	string ids3[17] = { "35","36","37","38","39","40","41","42","43","44","45","46","47","48","49","50","51" };
	string ids4[17] = { "52","53","54","55","56","57","58","59","60","61","62","63","64","65","66","67","68" };
	string ids5[17] = { "69","70","71","72","73","74","75","76","77","78","79","80","81","82","83","84","85" };
	int i,j,l;
	referee** Referee = new referee*[4];
	Referee[0] = new referee(referees[0], referees[1], refereeid[0]);
	Referee[1] = new referee(referees[2], referees[3], refereeid[1]);
	Referee[2] = new referee(referees[4], referees[5], refereeid[2]);
	Referee[3] = new referee(referees[6], referees[7], refereeid[3]);
	Teams = new team*[5];
	//srand(time(NULL));
	Teams[0] = new team(teams[0], names, family, stadiums[0], ids, city[0]);
	Teams[1] = new team(teams[1], names, family, stadiums[1], ids2, city[1]);
	Teams[2] = new team(teams[2], names, family, stadiums[2], ids3, city[2]);
	Teams[3] = new team(teams[3], names, family, stadiums[3], ids4, city[3]);
	Teams[4] = new team(teams[4], names, family, stadiums[4], ids5, city[4]);
	Workers = new worker*[89];
	for (i = 0; i < 4; i++) {
		Workers[i] = Referee[i];
		workers_num++;
	}
	Games = new game*[20];
	int ref1 = 0, ref2 = 0, ref3 = 0;
	for (i=0,l = 1; l < 5; i++,l++) {
		ref1 = 0; 
		ref2 = 0; 
		ref3 = 0;
		while (ref1 == ref2 || ref1 == ref3 || ref2 == ref3) {
			ref1 = rand() % 4;
			ref2 = rand() % 4;
			ref3 = rand() % 4;
		}
		Referee[ref1]->UpdateGames();
		Referee[ref2]->UpdateGames();
		Referee[ref3]->UpdateGames();
		Referee[ref1]->UpdateGames();
		Referee[ref2]->UpdateGames();
		Referee[ref3]->UpdateGames();
		Games[i++] = new game(*Teams[0], *Teams[l], *Referee[ref1], *Referee[ref2], *Referee[ref3]);
		Games[i] = new game(*Teams[l], *Teams[0], *Referee[ref1], *Referee[ref2], *Referee[ref3]);
	}
	for (i = 8, l = 2; l < 5; i++, l++) {
		ref1 = 0; 
		ref2 = 0; 
		ref3 = 0;
		while (ref1 == ref2 || ref1 == ref3 || ref2 == ref3) {
			ref1 = rand() % 4;
			ref2 = rand() % 4;
			ref3 = rand() % 4;
		}
		Referee[ref1]->UpdateGames();
		Referee[ref2]->UpdateGames();
		Referee[ref3]->UpdateGames();
		Referee[ref1]->UpdateGames();
		Referee[ref2]->UpdateGames();
		Referee[ref3]->UpdateGames();
		Games[i++] = new game(*Teams[1], *Teams[l], *Referee[ref1], *Referee[ref2], *Referee[ref3]);
		Games[i] = new game(*Teams[l], *Teams[1], *Referee[ref1], *Referee[ref2], *Referee[ref3]);
	}
	for (i = 14, l = 3; l < 5; i++, l++) {
		ref1 = 0;
		ref2 = 0;
		ref3 = 0;
		while (ref1 == ref2 || ref1 == ref3 || ref2 == ref3) {
			ref1 = rand() % 4;
			ref2 = rand() % 4;
			ref3 = rand() % 4;
		}
		Referee[ref1]->UpdateGames();
		Referee[ref2]->UpdateGames();
		Referee[ref3]->UpdateGames();
		Referee[ref1]->UpdateGames();
		Referee[ref2]->UpdateGames();
		Referee[ref3]->UpdateGames();
		Games[i++] = new game(*Teams[2], *Teams[l], *Referee[ref1], *Referee[ref2], *Referee[ref3]);
		Games[i] = new game(*Teams[l], *Teams[2], *Referee[ref1], *Referee[ref2], *Referee[ref3]);
	}
	for (i = 18, l = 4; l < 5; i++, l++) {
		ref1 = 0;
		ref2 = 0;
		ref3 = 0;
		while (ref1 == ref2 || ref1 == ref3 || ref2 == ref3) {
			ref1 = rand() % 4;
			ref2 = rand() % 4;
			ref3 = rand() % 4;
		}
		Referee[ref1]->UpdateGames();
		Referee[ref2]->UpdateGames();
		Referee[ref3]->UpdateGames();
		Referee[ref1]->UpdateGames();
		Referee[ref2]->UpdateGames();
		Referee[ref3]->UpdateGames();
		Games[i++] = new game(*Teams[3], *Teams[l], *Referee[ref1], *Referee[ref2], *Referee[ref3]);
		Games[i] = new game(*Teams[l], *Teams[3], *Referee[ref1], *Referee[ref2], *Referee[ref3]);
	}
	//--------------------------------------------------------------
	for (i = 4,j=0; i < 19; i++,j++) {
		Workers[i] = Teams[0]->GetPlayer(j);
		workers_num++;
	}
	Workers[i++] = Teams[0]->GetCoach();
	Workers[i] = Teams[0]->GetManager();
	workers_num += 2;
	for (i = 21, j = 0; i < 36; i++, j++) {
		Workers[i] = Teams[1]->GetPlayer(j);
		workers_num++;
	}
	Workers[i++] = Teams[1]->GetCoach();
	Workers[i] = Teams[1]->GetManager();
	workers_num += 2;
	for (i = 38, j = 0; i < 53; i++, j++) {
		Workers[i] = Teams[2]->GetPlayer(j);
		workers_num++;
	}
	Workers[i++] = Teams[2]->GetCoach();
	Workers[i] = Teams[2]->GetManager();
	workers_num += 2;
	for (i =55 , j = 0; i < 70; i++, j++) {
		Workers[i] = Teams[3]->GetPlayer(j);
		workers_num++;
	}
	Workers[i++] = Teams[3]->GetCoach();
	Workers[i] = Teams[3]->GetManager();
	workers_num += 2;
	for (i = 72, j = 0; i < 87; i++, j++) {
		Workers[i] = Teams[4]->GetPlayer(j);
		workers_num++;
	}
	Workers[87] = Teams[4]->GetCoach();
	Workers[88] = Teams[4]->GetManager();
	workers_num += 2;
}

Ligat_HaAl::~Ligat_HaAl()
{
	int i;
	for (i = 0; i < 5; i++) {
		Teams[i]->~team();
	}
	delete[] Teams;
	for (i = 0; i < 20 ; i++) {
		Games[i]->~game();
	}
	delete[] Games;
	/*for (i = 0; i < workers_num; i++) {
		delete Workers[i];
	}*/
	delete[] Workers;
}

void Ligat_HaAl::Menu()
{
	int index;
	do {
		PrintMenu();
		cin >> index;
		switch (index) {
		 case 1: {
			AddFootballer();
			break;
		}
		 case 2: {
			AddReferee();
			break;
		}
		 case 3: {
			int i, select;
			cout << "wich team you want to print?" << endl;
			for (i = 0; i < 5; i++) {
				cout << i + 1 << "." << Teams[i]->GetName() << endl;
			}
			cin >> select;
			Teams[select - 1]->PrintTeam();
			break;
		}
		 case 4: {
			int i, j, l;
			for (i = 0; i < workers_num; i++) {
				referee *ref = dynamic_cast<referee*>(Workers[i]);
				if (ref) {
					ref->PrintReferee();
					for (j = 0; j < 20; j++) {
						for (l = 0; l < 3; l++) {
							if (Games[j]->Referees[l]->GetId() == ref->GetId()) {
								Games[j]->date->PrintDate();
								cout << Games[j]->Team1->GetName() << " vs " << Games[j]->Team2->GetName() << endl;
							}
						}
					}
				}
			}
			break;
		}
		 case 5: {
			int day, month, i,count=0;
			cout << "insert day and month to check(numbers)" << endl;
			cin >> day;
			cin >> month;
			for (i = 0; i < 20; i++) {
				if (Games[i]->date->GetMonth() > month) {
					Games[i]->date->PrintDate();
					cout << Games[i]->Team1->GetName() << " vs " << Games[i]->Team2->GetName() << endl;
					count++;
				}
				else if (Games[i]->date->GetMonth() == month) {
					if (Games[i]->date->GetDay() > day) {
						Games[i]->date->PrintDate();
						cout << Games[i]->Team1->GetName() << " vs " << Games[i]->Team2->GetName() << endl;
						count++;
					}
				}
			}
			if (count == 0) {
				cout << "no future game" << endl;
			}
			break;
		}
		 case 6: {
			string idch;
			int i, count = 0;
			cout << "insert worker id for check" << endl;
			cin >> idch;
			for (i = 0; i < workers_num; i++) {
				if (Workers[i]->Id == idch) {
					cout << "the salary of this worker it: ";
					cout << Workers[i]->Salary() << endl;
					count++;
				}
			}
			if (count == 0) {
				cout << "no worker exist" << endl;
			}
			break;
		 }
		 case 7: {
			int i, select;
			string idch;
			cout << "select game from the list:" << endl;
			for (i = 0; i < 20; i++) {
				cout << i + 1 << ".";
				Games[i]->date->PrintDate();
				cout << Games[i]->Team1->GetName() << " vs " << Games[i]->Team2->GetName() << endl;
			}
			getchar();
			cin >> select;
			select -= 1;
			cout << "insert the id of the player who score" << endl;
			cin >> idch;
			*Games[select] += idch;
			/*for (i = 0; i < Games[select]->Team1->GetSize(); i++) {
				if (Games[select]->Team1->GetSquad()[i]->GetId() == idch) {
					Games[select]->Team1->GetSquad()[i]->AddGoal();
					Games[select]->Goals1++;
					Games[select]->Winner = Games[select]->Team1->GetName();
					flag = true;
				}
			}
			for (i = 0; i < Games[select]->Team2->GetSize(); i++) {
				if (Games[select]->Team2->GetSquad()[i]->GetId() == idch) {
					Games[select]->Team2->GetSquad()[i]->AddGoal();
					Games[select]->Goals2++;
					Games[select]->Winner = Games[select]->Team2->GetName();
					flag = true;
				}
			}
			if (!flag) {
				cout << "this player is not a player of each team in this game" << endl;
			}*/
			break;
		}
		 case 8: {
			int i, mistakes;
			string idch;
			bool flag = false;
			cout << "insert id of the referee you want to update his mistakes" << endl;
			cin >> idch;
			cout << "how much mistakes you want to add?" << endl;
			cin >> mistakes;
			for (i = 0; i < workers_num; i++) {
				referee* ref = dynamic_cast<referee*>(Workers[i]);
				if (ref) {
					if (ref->GetId() == idch) {
						ref->UpdateMis(mistakes);
						flag = true;
					}
				}
			}
			if (!flag) {
				cout << "this id not belong to referee" << endl;
			}
			break;
		}
		 case 9: {
			int i;
			for (i = 0; i < workers_num; i++) {
				if (Workers[i]->OutStanding()) {
					footballer* player = dynamic_cast<footballer*>(Workers[i]);
					manager* mng = dynamic_cast<manager*>(Workers[i]);
					coach* coh = dynamic_cast<coach*>(Workers[i]);
					referee* ref = dynamic_cast<referee*>(Workers[i]);
					if (player) {
						player->PrintFootballer();
					}
					if (mng) {
						mng->PrintWorker();
					}
					if (coh) {
						coh->PrintCoach();
						if (coh->GetFormer()) {
							cout << "the coach is former footballer" << endl;
						}
						else {
							cout << "the coach isnt former footballer" << endl;
						}
					}
					if (ref) {
						ref->PrintReferee();
						if (ref->GetMistakes() == ref->GetMaxMis()) {
							cout << "this referee have the max mistakes" << endl;
						}
					}
				}
			}
			break;
		}
		 case 10: {
			int points[5] = { 0,0,0,0,0 }, i, j, l, place;
			for (i = 0; i < 20; i++) {
				for (j = 0; j < 5; j++) {
					if (Games[i]->Winner == Teams[j]->GetName()) {
						points[j] += 3;
					}
				}
				if (Games[i]->Winner == "tie") {
					for (l = 0; l < 5; l++) {
						if (Teams[l]->GetName() == Games[i]->Team1->GetName()) {
							points[l] += 1;
						}
						if (Teams[l]->GetName() == Games[i]->Team2->GetName()) {
							points[l] += 1;
						}
					}
				}
			}
			for (i = 0; i < 5; i++) {
				place = BiggerPoint(points);
				cout << i + 1 << "." << Teams[place]->GetName() << " " << points[place] << endl;
				points[place] = -1;
			}
			break;
		}
		 case 11: {
			int i, place;
			float min_salary = 1000000;
			for (i = 0; i < workers_num; i++) {
				footballer* player = dynamic_cast<footballer*>(Workers[i]);
				if (player) {
					if (player->Salary() < min_salary) {
						min_salary = player->Salary();
						place = i;
					}
				}
			}
			footballer* player = dynamic_cast<footballer*>(Workers[place]);
			if (player) {
				player->PrintFootballer();
			}
			break;
		}
		 case 12: {
			 cout << "good bye" << endl;
			break;
		}
		 default: 
			cout << "invalid selection" << endl;
			break;
		}
	}while (index != 12);
}
