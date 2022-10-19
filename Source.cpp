#include <iostream>
using namespace std;

class node
{
private:
	int data;
	node *next;

public:
	node(int value = 0)
	{
		data = value;
		next = NULL;
	}
	friend class linkedListQueue;
};
class linkedListQueue
{
private:
	node *front;
	node *back;
	int length;

public:
	linkedListQueue()
	{
		length = 0;
		front = NULL;
		back = NULL;
	}
	void menu()
	{
		char choice;
		do
		{
			cout << "1:Enqueue\n2:Dequeue\n3:Display\n4:Exit\nchoice:";
			cin >> choice;
			switch (choice)
			{
			case '1':
				system("cls");
				enqueue();
				break;
			case '2':
				system("cls");
				dequeue();
				break;
			case '3':
				system("cls");
				display();
				break;
			case '4':
				exit(0);
				break;
			default:
				break;
			}
		} while (choice < 1 || choice > 4);
	}
	void enqueue()
	{
		int value;
		cout << "Enter the value:";
		cin >> value;
		node *newNode = new node(value);
		if (front == NULL)
		{
			front = newNode;
			back = newNode;
			length++;
			return;
		}
		else
		{
			back->next = newNode;
			back = newNode;
			length++;
		}
	}

	void dequeue()
	{
		if (front == NULL)
		{
			cout << "Queue is empty!\n";
			return;
		}
		else
		{
			node *del = front;
			front = front->next;
			delete del;
			length--;
		}
	}
	void display()
	{
		if (front == NULL)
		{
			cout << "Queue is empty!\n";
			return;
		}
		else
		{
			node *temp = front;
			while (temp != back)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << temp->data << " ";
		}
		cout << endl;
	}
	bool isEmpty()
	{
		return front == NULL;
	}
	int getLength() const
	{
		return length;
	}
};
class arrayQueue
{
private:
	int front;
	int back;
	int length;
	int *array;
	int arraySize;

public:
	arrayQueue(int size = 5)
	{
		front = -1;
		back = -1;
		length = 0;
		arraySize = size;
		array = new int[arraySize];
	}
	bool isFull()
	{
		return length == arraySize;
	}
	bool isEmpty()
	{
		return front == -1;
	}
	void menu()
	{
		char choice;
		do
		{
			cout << "1:Enqueue\n2:Dequeue\n3:Display\n4:Exit\nchoice:";
			cin >> choice;
			switch (choice)
			{
			case '1':
				system("cls");
				enqueue();
				break;
			case '2':
				system("cls");
				dequeue();
				break;
			case '3':
				system("cls");
				display();
				break;
			case '4':
				exit(0);
				break;
			default:
				break;
			}
		} while (choice < 1 || choice > 4);
	}
	void enqueue()
	{
		int value;
		cout << "Enter the value:";
		cin >> value;
		if (isFull())
		{
			return;
		}
		if (isEmpty())
		{
			front = 0;
			array[++back] = value;
			length++;
		}
		else
		{
			back = (back + 1) % arraySize;
			array[back] = value;
			length++;
		}
	}
	void dequeue()
	{
		if (isEmpty())
		{
			return;
		}
		else
		{
			front = (front + 1) % arraySize;
			length--;
		}
	}
	void display()
	{
		for (int i = 0; i < length; i++)
		{
			cout << array[(i + front) % arraySize] << " ";
		}
		cout << endl;
	}
};

int main()
{
	/*cout << "Linked list queue\n";
	linkedListQueue llq;
	llq.menu();*/

	cout << "Array queue\n";
	cout << "enter the size of array:";
	int size;
	cin >> size;
	arrayQueue aq(size);
	aq.menu();
	return 0;
}