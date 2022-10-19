#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int value=0)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};
class doublyLinkedList
{
public:
    Node* head;
    Node* tail;
    static int length;
    // constructor
    doublyLinkedList()
    {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    // functions
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insertAtIndex()
    {
        if (head == NULL)
        {
            return;
        }

        else
        {
            int value;
            cout << "Enter the value:";
            cin >> value;

            int index;
            cout << "Enter the index:";
            cin >> index;

            if (index > length)
            {
                cout << "Index out of range" << endl;
                return;
            }
            if (index == 0)
            {
                insertAtHead(value);
                return;
            }
            else
            {
                Node* temp = head;
                Node* newNode = new Node(value);
                int i = 0;
                while (i < index - 1)
                {
                    temp = temp->next;
                    i++;
                }
                if (temp->next == NULL)
                {
                    insertAtTail(value);
                    return;
                }
                newNode->next = temp->next;
                temp->next->prev = newNode;
                temp->next = newNode;
                newNode->prev = temp;
                length++;
            }
        }
    }

    void insertAtHead(int value)
    {
        Node* newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            length++;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            length++;
        }
    }

    void displayReverse()
    {
        Node* temp = tail;
        cout << "tail->";
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->prev;
        }
        cout << "head\n";
    }

    void insertAtTail(int value)
    {
        if (head == NULL)
        {
            insertAtHead(value);
        }
        else
        {
            Node* newNode = new Node(value);
            Node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            length++;
        }
    }

    void insertAtAnyPosition(int position, int value)
    {
        if (position == 0)
        {
            insertAtHead(value);
        }
        else
        {
            int count = 0;
            Node* temp = head;
            Node* newNode = new Node(value);
            for (int i = 1; i < position; i++)
            {
                temp = temp->next;
            }

            // 1 2 3
            // 1 0 2 3

            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
            length++;
        }
    }

    void deleteAtHead()
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            // 1-2-3
            Node* temp = head;
            head = head->next;
            if (head->next != NULL)
            {
                head->prev = NULL;
            }
            delete temp;
            length--;
        }
    }

    void display()
    {
        Node* temp = head->next;
        cout << "HEAD->";
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "TAIL\n";
    }

    void deleteNode()
    {
        display();
        int value;
        cout << "Enter the value you wanna delete:";
        cin >> value;
        if (head == NULL)
        {
            return;
        }

        while (head != NULL && head->data == value)
        { // del at head
            if (head == NULL)
            {
                return;
            }
            else
            {
                // 1-2-3
                Node* temp = head;
                head = head->next;
                if (head->next != NULL)
                {
                    head->prev = NULL;
                }
                delete temp;
                length--;
            }
        }
        Node* temp = head;

        while (temp != NULL)
        { // del after head
            if (temp->next != NULL && temp->next->data == value)
            {
                Node* del = temp->next;
                temp->next = temp->next->next;
                if (temp->next != NULL)
                {
                    temp->next->prev = temp;
                }
                delete del;
                length--;
            }
            else
            {
                temp = temp->next;
            }
        }
    }

    int getLength()
    {
        return length;
    }

    void sort(){
        Node* temp = head;
        while(temp->next != NULL){
            Node* temp2 = temp->next;
            while(temp2 != NULL){
                if(temp->data > temp2->data){
                    int temp3 = temp->data;
                    temp->data = temp2->data;
                    temp2->data = temp3;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }

    void insertBefore()
    {
        int value;
        cout << "Enter the value you wanna enter:";
        cin >> value;

        int key;
        cout << "Enter the value you wanna enter before:";
        cin >> key;

        Node* newNode = new Node(value);
        Node* temp = head;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                newNode->next = temp;
                newNode->prev = temp->prev;
                if (temp->prev == NULL)
                {
                    head = newNode;
                }
                else
                {
                    temp->prev->next = newNode;
                }
                temp->prev = newNode;
                length++;
            }
            temp = temp->next;
        }
    }
};

int doublyLinkedList::length = 0;

int main()
{
    doublyLinkedList L1;

    L1.insertAtHead(0);
    L1.insertAtTail(3);
    L1.insertAtTail(2);
    L1.insertAtTail(2);
    L1.insertAtTail(2);
    L1.insertAtTail(2);
    L1.insertAtTail(2);
    L1.insertAtTail(2);
    L1.insertAtTail(1);

    L1.display();

    /*L1.insertAtAnyPosition(1, 0);
    L1.display();*/

    // L1.deleteAtHead();
    // L1.display();

    // L1.displayReverse();
    // L1.deleteNode();
    // L1.display();

    // L1.insertBefore();
    // L1.display();

   /* L1.insertAtIndex();
    L1.display();*/
    L1.display();

    L1.sort();
    cout << L1.tail->data;
    L1.display();

    cout << "Length:" << L1.getLength() << endl;

    return 0;
}
