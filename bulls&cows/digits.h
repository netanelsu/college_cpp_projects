#include<iostream>
using namespace std;
class digit {
	friend class number;
private:
	int value;
public:
	digit();
	void SetValue(int);
	int GetValue();
	bool Compare(const int&)const;
	
};