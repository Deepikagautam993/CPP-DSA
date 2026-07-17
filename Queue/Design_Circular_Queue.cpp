#include <iostream>
using namespace std;

const int SIZE = 5;

int arr[SIZE];
int front = -1;
int rear = -1;


bool isEmpty()
{
    return (front == -1);
}


bool isFull()
{
    return ((rear + 1) % SIZE == front);
}


void enQueue(int value)
{
    if(isFull())
    {
        cout << "Queue Overflow!" << endl;
        return;
    }

    if(isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % SIZE;
    }

    arr[rear] = value;

    cout << value << " inserted successfully." << endl;
}


void deQueue()
{
    if(isEmpty())
    {
        cout << "Queue Underflow!" << endl;
        return;
    }

    cout << arr[front] << " deleted successfully." << endl;

    // Only one element present
    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}


int Front()
{
    if(isEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return -1;
    }

    return arr[front];
}


int Rear()
{
    if(isEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return -1;
    }

    return arr[rear];
}


void display()
{
    if(isEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return;
    }

    cout << "Queue : ";

    int i = front;

    while(true)
    {
        cout << arr[i] << " ";

        if(i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    cout << endl;
}

int main()
{
    enQueue(10);
    enQueue(20);
    enQueue(30);
    enQueue(40);
    enQueue(50);

    display();

    cout << "Front : " << Front() << endl;
    cout << "Rear  : " << Rear() << endl;

    deQueue();
    deQueue();

    display();

    enQueue(60);
    enQueue(70);

    display();

    cout << "Front : " << Front() << endl;
    cout << "Rear  : " << Rear() << endl;

    return 0;
}
