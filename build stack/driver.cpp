#include<iostream>
#include"stack.h"
using namespace std;
int main() {
	Stack first, second;  
	for (int i = 10; i < 15; i++) { 
		first += i;   
		second += i; 
	}
	cout << "First Stack:" << endl<< first << "Second Stack  :" << endl << second << endl;
	if (first == second)
		cout << "the stacks are equals !" << endl;
	else 
		cout << "the stacks are different !" << endl;
    first -= 1;  
	second -= 3;
	cout << endl << "After  deleting :" << endl << "First Stack :" << endl << first << "Second Stack :" << endl << second << endl;  
	if (first != second)   
		cout << "the stacks are different !" << endl;
	else   
		cout << "the stacks are equals !" << endl;
	cout << "Reverse form of the first stack :" << endl << !first << endl;
	cout << "Delete top from first stack :" << endl << (first -= 1) << endl;
	Stack third(first);
	cout << " Third stack :" << endl << third;
	return 0;
}