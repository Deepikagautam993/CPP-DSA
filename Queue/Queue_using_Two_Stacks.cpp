#include <iostream>
#include <stack>
using namespace std;

class Queue
{
private:
    stack<int> s1, s2;

public:

    // Check Queue Empty
    bool isEmpty()
    {
        return s1.empty();
    }

    // Enqueue (Costly)
    void enqueue(int value)
    {
        // Step 1: Move all elements from s1 to s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // Step 2: Push new element into s1
        s1.push(value);

        // Step 3: Move all elements back to s1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

        cout << value << " inserted into Queue." << endl;
    }

    // Dequeue (Easy)
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!" << endl;
            return;
        }

        cout << s1.top() << " deleted from Queue." << endl;
        s1.pop();
    }

    // Front Element
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        return s1.top();
    }

    // Rear Element
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        stack<int> temp = s1;

        while (temp.size() > 1)
        {
            temp.pop();
        }

        return temp.top();
    }

    // Display Queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        stack<int> temp = s1;

        cout << "Queue : ";

        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }

        cout << endl;
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

    cout << "Front : " << q.getFront() << endl;
    cout << "Rear  : " << q.getRear() << endl;

    return 0;
}
