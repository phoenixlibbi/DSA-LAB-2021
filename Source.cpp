#include<iostream>
using namespace std;

class node {
private:
	int data;
	node* next;
public:
	node(int value = 0) {
		data = value;
		next = nullptr;
	}
	friend class circularLinkedList;
};

class circularLinkedList {
private:
	node* head;
public:
	circularLinkedList() {
		head = new node();
		head->next = head;
	}
	void insert(int value) {
		node* newNode = new node(value);  //head->head
		newNode->next = head->next;       //0->head
		head->next = newNode;             //head->0->head
	}

	void insertAtEnd(int value) {
		if (head->next == head) {
			insert(value);
		}
		else {
			node* newNode = new node(value);  //head->1->2->3->head
			node* i = head->next;
			while (i->next != head) {
				i = i->next;
			}
			i->next = newNode;
			newNode->next = head;
		}
	}

	void deleteNode(int value) {
		//head->1->2->3->head
		node* i = head;
		while (i->next != head) {
			if (i->next->data == value) {
				node* del = i->next;
				i->next = i->next->next;
				delete del;
			}
			else {
				i = i->next;
			}
		}
	}

	void display() {
		cout << "head->";
		node* i = head->next;
		while (i != head) {
			cout << i->data << "->";
			i = i->next;
		}
		cout << "head\n";
	}
};

int main() {
	circularLinkedList c;

	c.insert(3);
	c.insert(2);
	c.insert(1);
	c.display();

	c.insertAtEnd(4);
	c.insertAtEnd(4);
	c.insertAtEnd(4);
	c.insertAtEnd(5);
	c.insertAtEnd(4);
	c.insertAtEnd(6);
	c.display();

	c.deleteNode(4);
	c.display();
}
