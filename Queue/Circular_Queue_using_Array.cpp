#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Constructor
    CircularQueue(int s)
    {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Check Empty
    bool isEmpty()
    {
        return front == -1;
    }

    // Check Full
    bool isFull()
    {
        return (rear + 1) % size == front;
    }

    // Insert
    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue Overflow!" << endl;
            return;
        }

        // First Element
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;

        cout << value << " inserted." << endl;
    }

    // Delete
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!" << endl;
            return;
        }

        cout << arr[front] << " deleted." << endl;

        // Only One Element
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }

    // Front Element
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        return arr[front];
    }

    // Rear Element
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        return arr[rear];
    }

    // Display Queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue : ";

        int i = front;

        while (true)
        {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % size;
        }

        cout << endl;
    }

    // Destructor
    ~CircularQueue()
    {
        delete[] arr;
    }
};

int main()
{
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    cout << "Front : " << q.getFront() << endl;
    cout << "Rear  : " << q.getRear() << endl;

    return 0;
}
