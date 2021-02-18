#include "definition.h"

Definition::~Definition()
{
	int i;
	for (i = 0; i < defnum; i++) {
		definitions[i]->~String();
	}
	delete[]definitions;
}

const Definition & Definition::operator=(const Definition & obj)
{
	int i;
	if (this != &obj) {
		for (i = 0; i < defnum; i++) {
			 definitions[i]->~String();
		 }
		delete[]definitions;
		word = obj.word;
		defnum = obj.defnum;
		definitions = new String*[defnum];
		for (i = 0; i < defnum; i++) {
			definitions[i] = new String;
		}
		for(i=0;i<defnum;i++){
			*definitions[i] = *obj.definitions[i];
		}
	}
	return *this;
}

bool Definition::operator==(const Definition & obj) const
{
	bool flag;
	flag = word == obj.word;
	return flag;
}

const Definition & Definition::operator-=(int serial)
{
	int i,j=0;
	Definition temp;
	temp.word = this->word;
	temp.defnum = this->defnum-1;
	temp.definitions = new String*[temp.defnum];
	for (i = 0; i < temp.defnum; i++) {
		temp.definitions[i] = new String;
	}
	for (i = 0; i < this->defnum; i++) {
		if (i != serial-1) {
			*temp.definitions[j] = *this->definitions[i];
			j++;
		}
	}
	*this = temp;
	return *this;
}

const Definition & Definition::operator+=(const String& newdef)
{
	int i,count=0;
	Definition temp;
	for (i = 0; i < this->defnum; i++) {
		if (*this->definitions[i] != newdef) {
			count++;
		}
	}
	if (count == this->defnum) {
		temp.word = this->word;
		temp.defnum = (this->defnum + 1);
		temp.definitions = new String*[temp.defnum];
		for (i = 0; i < temp.defnum; i++) {
			temp.definitions[i] = new String;
		}
		for (i = 0; i < this->defnum; i++) {
			*temp.definitions[i] = *this->definitions[i];
		}
		*temp.definitions[i] = newdef;
		*this = temp;
	}
	return *this;
}

String & Definition::operator[](int index)
{
	return *definitions[index-1];
}

ostream & operator<<(ostream & out, const Definition & obj)
{
	int i;
	out << obj.word <<":-"<<endl;
	for (i = 0; i < obj.defnum; i++) {
		out << i + 1 << "." << *obj.definitions[i] << endl;
	}
	return out;
}
istream & operator>>(istream & in, Definition & obj)
{
	int j,count = 0;
	cout << "insert a word to define" << endl;
	cin >> obj.word;
	obj.word.BuildString();
	cout << "how many definitions you want to insert?" << endl;
	cin >> obj.defnum;
	obj.definitions = new String*[obj.defnum];
	for (int i = 0; i < obj.defnum; i++) {
		obj.definitions[i] = new String;
	}
	getchar();
	cout << "please insert the definitions" << endl;
	for (int i = 0; i < obj.defnum; i++) {
		cin>>*obj.definitions[i];
		obj.definitions[i]->BuildString();
		count = 0;
		for (j = 0; j < i; j++) {
			if (*obj.definitions[i] == *obj.definitions[j]) {
				count++;
			}
		}
		if (count > 0) {
			cout << "this definition already exist,insert new one" << endl;
			i--;
		}
	}
	return in;
}
