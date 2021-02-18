#include<iostream>
using namespace std;
class OrderSet {
private:
	int *group;
	int size;
	int CheckArr(int*, int);
	bool CheckSort(int*,int);
	void Sorter(int**, int);
public:
	OrderSet();
	OrderSet(int*, int);
	OrderSet(const OrderSet &obj);
	~OrderSet();
	int* getGroup();
	int getSize();
	void print();
	bool ChangeGroup(int*,int);
	OrderSet DiffGroup(OrderSet);
	OrderSet InterSect(OrderSet);
	OrderSet UnionGroup(OrderSet);
	bool EqualGroup(OrderSet);
	bool EmptyGroup();
	bool Contain(int);
	bool Contain(OrderSet);
};


