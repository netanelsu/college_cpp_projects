#include "stack.h"

Stack::Stack(const Stack &obj)
{
	*this = obj;
}

Stack::~Stack()
{
	cout << "stack detor" << endl;
	Node* temp = head;
	while (head->next!=NULL) {
		head = head->next;
		delete temp;
		temp = head;
	}
	delete head;
}

const Stack& Stack::operator=(const Stack &obj)
{
	Node *temp = obj.head;
	if (this->head != NULL) {
		this->~Stack();
	}
	while (temp != NULL) {
		*this += temp->value;
		 temp= temp->next;
	}
	!*this;
	return *this;
}

const Stack& Stack::operator+=(int value)
{
	if (head == NULL) {
		head = new Node(value);
		size++;
	}
	else {
		Node *temp=head;
		head = new Node(value);
		size++;
		head->next = temp;
	}
	return *this;
}

Stack & Stack::operator-=(int value)
{
	if (value > size||value<1) {
		cout << "invaild value" << endl;
	}
	Node *temp;
	size -= value;
	while (value > 0) {
		temp = head;
		head = head->next;
		delete temp;
		value--;
	}
	return *this;
}

bool Stack::operator==(const Stack &obj)
{
	if (size != obj.size) {
		return false;
	}
	else {
		Node* temp1,*temp2;
		temp1 = head;
		temp2 = obj.head;
		for (int i = 0; i < size; i++) {
			if (temp1->value != temp2->value) {
				return false;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		return true;
	}
}

bool Stack::operator!=(const Stack &obj)
{
	if (size != obj.size) {
		return true;
	}
	else {
		Node* temp1, *temp2;
		temp1 = head;
		temp2 = obj.head;
		for (int i = 0; i < size; i++) {
			if (temp1->value != temp2->value) {
				return true;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		return false;
	}
}

Stack & Stack::operator!()
{
	Node *current = head;
	Node* prev = NULL;
	Node* next = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return *this;
}

void Stack::PrintStack()
{
	Node *temp=head;
	while (temp != NULL) {
		temp->print();
		temp = temp->next;
	}
}

Stack::Node::Node(const Node& obj)
{
	value = obj.value;
	if (obj.next == NULL) {
		next = NULL;
	}
	else {
		next = new Node(*(obj.next));
	}
}
ostream & operator<<(ostream & out,  Stack& obj)
{
	obj.PrintStack();
	return out;
}