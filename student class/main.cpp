#include"class.h"
#include<iostream>
#include<string.h>
int main(){
	char Name[51];
	long Id;
	int Course,Stip;
	cout << "please insert student full name" << endl;
	cin.getline(Name,51);
	cout << "please insert student id" << endl;
	cin >> Id;
	cout << "please insert number of courses" << endl;
	cin >> Course;
	cout << "please insert stipend value" << endl;
	cin >> Stip;
	student stu1(Name,Id,Course,Stip);
	getchar();
	cout << "please insert student full name" << endl;
	cin.getline(Name,51);
	cout << "please insert student id" << endl;
	cin >> Id;
	cout << "please insert number of courses" << endl;
	cin >> Course;
	cout << "please insert stipend value" << endl;
	cin >> Stip;
	student stu2(Name, Id, Course, Stip);
	getchar();
	student stu3 = stu1;
	return 0;
}