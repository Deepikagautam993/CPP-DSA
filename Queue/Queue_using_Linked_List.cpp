#include <iostream>
using namespace std;

// Node of Linked List
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    // Constructor
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    // Check Empty
    bool isEmpty()
    {
        return front == NULL;
    }

    // Insert Element
    void enqueue(int value)
    {
        Node *newNode = new Node(value);

        // Queue Empty
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << value << " inserted into Queue." << endl;
    }

    // Delete Element
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!" << endl;
            return;
        }

        Node *temp = front;

        cout << temp->data << " deleted from Queue." << endl;

        // Only one element
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
        }

        delete temp;
    }

    // Front Element
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        return front->data;
    }

    // Rear Element
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        return rear->data;
    }

    // Display Queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        Node *temp = front;

        cout << "Queue : ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Destructor
    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << "Front : " << q.getFront() << endl;
    cout << "Rear  : " << q.getRear() << endl;

    q.dequeue();

    q.display();

    q.enqueue(40);

    q.display();

    return 0;
}
