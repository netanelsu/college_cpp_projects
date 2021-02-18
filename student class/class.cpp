#include "class.h"
#include<iostream>
#include<string.h>
//void student::setName(char Name[51])
//{
//	strcpy(name, Name);
//}

void student::setName(char Name[51])
{
	strcpy_s(name, 51, Name);
}

char* student::getName()
{
	return name;
}

void student::setId(long Id)
{
	id = Id;
}

long student::getId()
{
	return id;
}

void student::setCourse(int course)
{
	courses = course;
}

int student::getCourse()
{
	return courses;
}

void student::setStip(int stip)
{
	stipend = stip;
}

int student::getStip()
{
	return stipend;
}

void student::print()
{
	cout << "student name:" << name << endl;
	cout << "student id:" << id << endl;
	cout << "number of courses:" << courses << endl;
	cout << "stipend value:" << stipend << endl;
}

int student::calTuition(int course,int stip)
{
	int tuition;
	tuition = (1500 * course)-stip;
	if (tuition < 0) {
		return 0;
	}
	return tuition;
}

student::student(char *Name, long Id, int Course, int Stip)
{
	int tuition;
	tuition = calTuition(Course, Stip);
	strcpy_s(name, 51, Name);
	id = Id;
	if (Course == 0)
	{
		courses = 0;
	}
	else {
		courses = Course;
	}
	if (Stip == 0)
	{
		stipend = 0;
	}
	else {
		stipend = Stip;
	}
	print();
	cout << "tuition fee is:" << tuition << endl;
}

student::student(const student & obj)
{
	int tuition = calTuition(obj.courses, obj.stipend);
	strcpy_s(name,51,obj.name);
	id = obj.id;
	courses = obj.courses;
	stipend = obj.stipend;
	print();
	cout << "tuition fee is:" << tuition << endl;
}
