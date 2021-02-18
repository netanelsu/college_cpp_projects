#include"orderedset.h"
#include<iostream>
int main() {
	int arr1[10] = { 1,8,5,5,7,9,2,3,6,11 };
	int arr2[7] = { 1,2,3,4,11,12,21 };
	int arr3[6] = { 8,3,5,2,11,9 };
	bool flag;
	int number;
	OrderSet p1(arr1,10),p2(arr3,6);
	cout << "first group is:" << endl;
	p1.print();
	cout << "second group is:" << endl;
	p2.print();
	flag=p1.ChangeGroup(arr2, 7);
	if (flag) {
		cout << "first group change to:" << endl;
		p1.print();
	}
	OrderSet p3 = p1.DiffGroup(p2);
	cout << "the diffrence group is:" << endl;
	p3.print();
	OrderSet p4 = p1.InterSect(p2);
	cout << "the intersection group is:" << endl;
	p4.print();
	OrderSet p5 = p1.UnionGroup(p2);
	cout << "the union group is:" << endl;
	p5.print();
	flag = p1.EqualGroup(p2);
	if (!flag) {
		cout << "the groups are not equal" << endl;
	}
	else {
		cout << "the groups are equal" << endl;
	}
	flag = p2.EmptyGroup();
	cout << "please insert integer number" << endl;
	cin >> number;
	flag = p1.Contain(number);
	if (!flag) {
		cout << "the number:"<<number<<" not contain in the group" << endl;
	}
	else {
		cout << "the number:"<<number<<" contain in the group" << endl;
	}
	flag = p1.Contain(p2);
	if (!flag) {
		cout << "the group:";
		p2.print();
		cout<<"not contain in the group:";
		p1.print();
	}
	else {
		cout << "the group:";
		p2.print();
		cout << "contain in the group:";
		p1.print();
	}
	return 0;
}