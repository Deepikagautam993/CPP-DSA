#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Constructor
    Queue(int s)
    {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Check Queue Empty
    bool isEmpty()
    {
        return (front == -1);
    }

    // Check Queue Full
    bool isFull()
    {
        return (rear == size - 1);
    }

    // Insert Element
    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue Overflow!\n";
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear++;
        }

        arr[rear] = value;
        cout << value << " inserted into Queue.\n";
    }

    // Delete Element
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!\n";
            return;
        }

        cout << arr[front] << " deleted from Queue.\n";

        // Only one element
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }

    // Get Front Element
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!\n";
            return -1;
        }

        return arr[front];
    }

    // Get Rear Element
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!\n";
            return -1;
        }

        return arr[rear];
    }

    // Display Queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << "Queue : ";

        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // Destructor
    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << "Front : " << q.getFront() << endl;
    cout << "Rear  : " << q.getRear() << endl;

    q.dequeue();

    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // Overflow

    q.display();

    return 0;
}
