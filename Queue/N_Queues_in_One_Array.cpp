#include <iostream>
using namespace std;

class NQueue
{
private:
    int n;              // Size of array
    int k;              // Number of queues
    int *arr;           // Data array
    int *front;         // Front of each queue
    int *rear;          // Rear of each queue
    int *next;          // Link array
    int freeSpot;       // Next free index

public:

    NQueue(int queues, int size)
    {
        k = queues;
        n = size;

        arr = new int[n];

        front = new int[k];
        rear = new int[k];

        next = new int[n];

        // Initially all queues empty
        for(int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }


        // Creating free list
        for(int i = 0; i < n - 1; i++)
        {
            next[i] = i + 1;
        }

        next[n - 1] = -1;

        // First free position
        freeSpot = 0;
    }

    // Insert element
    bool enqueue(int value, int queueNumber)
    {
        // No space available
        if(freeSpot == -1)
        {
            cout << "Queue Overflow" << endl;
            return false;
        }

        // Find free index
        int index = freeSpot;

        // Update free spot
        freeSpot = next[index];

        // First element in queue
        if(front[queueNumber] == -1)
        {
            front[queueNumber] = index;
        }
        
        else
        {
            // Link previous node
            next[rear[queueNumber]] = index;
        }

        // Update rear
        rear[queueNumber] = index;

        // Mark end
        next[index] = -1;

        // Insert value
        arr[index] = value;

        return true;
    }

    // Remove element
    int dequeue(int queueNumber)
    {
        // Queue empty
        if(front[queueNumber] == -1)
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }

        // Get index
        int index = front[queueNumber];

        // Move front
        front[queueNumber] = next[index];

        // Add index back to free list
        next[index] = freeSpot;

        freeSpot = index;

        return arr[index];
    }

    // Display particular queue
    void display(int queueNumber)
    {
        if(front[queueNumber] == -1)
        {
            cout << "Queue Empty" << endl;
            return;
        }

        int index = front[queueNumber];

        cout << "Queue " << queueNumber << " : ";

        while(index != -1)
        {
            cout << arr[index] << " ";

            index = next[index];
        }
        cout << endl;
    }

    ~NQueue()
    {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};


int main()
{
    // 3 Queues in one array of size 10
    NQueue q(3,10);
    q.enqueue(10,0);
    q.enqueue(20,0);
    q.enqueue(30,0);
    q.enqueue(100,1);
    q.enqueue(200,1);
    q.enqueue(500,2);

    q.display(0);
    q.display(1);
    q.display(2);

    cout << "Deleted : "
         << q.dequeue(0)
         << endl;

    q.display(0);

    return 0;
}
