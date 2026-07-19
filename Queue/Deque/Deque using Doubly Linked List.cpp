#include<iostream>
using namespace std;

class Node
{
public:

    int data;
    Node* prev;
    Node* next;

    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

Node* front = NULL;
Node* rear = NULL;

bool isEmpty()
{
    return front == NULL;
}

void insertFront(int x)
{
    Node* temp = new Node(x);

    if(isEmpty())
    {
        front = rear = temp;
        return;
    }

    temp->next = front;
    front->prev = temp;
    front = temp;
}

void insertRear(int x)
{
    Node* temp = new Node(x);

    if(isEmpty())
    {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    temp->prev = rear;
    rear = temp;
}

void deleteFront()
{
    if(isEmpty())
        return;

    if(front == rear)
    {
        delete front;
        front = rear = NULL;
        return;
    }

    Node* temp = front;

    front = front->next;
    front->prev = NULL;

    delete temp;
}

void deleteRear()
{
    if(isEmpty())
        return;

    if(front == rear)
    {
        delete rear;
        front = rear = NULL;
        return;
    }

    Node* temp = rear;

    rear = rear->prev;
    rear->next = NULL;

    delete temp;
}

int getFront()
{
    if(isEmpty())
        return -1;

    return front->data;
}

int getRear()
{
    if(isEmpty())
        return -1;

    return rear->data;
}

void display()
{
    Node* curr = front;

    while(curr)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }

    cout<<endl;
}

int main()
{
    insertRear(10);
    insertRear(20);
    insertRear(30);

    display();

    insertFront(5);

    display();

    deleteRear();

    display();

    deleteFront();

    display();

    cout<<"Front : "<<getFront()<<endl;
    cout<<"Rear : "<<getRear()<<endl;

    return 0;
}
