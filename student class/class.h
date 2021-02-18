#include<iostream>
#include<string.h>
using namespace std;
class student {
private:
	char name[51];
	long id;
	int courses;
	int stipend;
public:
	void setName(char Name[51]);
	char* getName();
	void setId(long Id);
	long getId();
	void setCourse(int course);
	int getCourse();
	void setStip(int stip);
	int getStip();
	void print();
	int calTuition(int course,int stip);
	student(char *Name,long Id,int Course,int Stip);
	student(const student &obj);
};


