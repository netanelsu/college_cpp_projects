#include<iostream>
using namespace std;
class Stack {
private:
	class Node {
	private:
		int value;
		Node* next;
		friend class Stack;
	public:
		Node(int value) :value(value), next(NULL) {};
		Node(const Node &);
		void print() { cout << value << endl; };
	};
	Node* head;
	int size;
public:
	Stack() :head(NULL), size(0){};
	Stack(const Stack&);
	~Stack();
	const Stack& operator =(const Stack&);
	const Stack& operator+=(int);
	Stack& operator-=(int);
	bool operator==(const Stack&);
	bool operator!=(const Stack&);
    Stack& operator!();
	void PrintStack();
	friend ostream& operator<<(ostream& , Stack& );
};