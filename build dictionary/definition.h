#include<iostream>
#include"String.h"
using namespace std;
class Definition {
private:
	String word;
	int defnum;
	String **definitions;
	friend class Dictionary;
	friend class Menu;
public:
	Definition() : word(), defnum(0), definitions(NULL) {};
	~Definition();
	const Definition& operator=(const Definition& obj);
	bool operator==(const Definition& obj)const;
	friend ostream& operator<<(ostream& out, const Definition& obj);
	friend istream& operator>>(istream& in, Definition& obj);
    const Definition& operator-=(int);
	const Definition& operator+=(const String&);
	String& operator[](int);
};