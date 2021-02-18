#include<iostream>
#include<string>
#include"manager.h"
using namespace std;
class stadium{
private:
	string Name;
	string City;
	int Capacity;
public:
	stadium(string name, string city) :Name(name), City(city) {
		//srand(time(NULL));
		Capacity = rand() % 85000 + 15000;
	}
	~stadium() {};
	void PrintStadium();
	string GetSName();
};

