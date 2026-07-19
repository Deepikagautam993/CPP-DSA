#include <iostream>
using namespace std;

int size;
int *arr;
int front = -1;
int rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return (rear + 1) % size == front;
}

bool insertFront(int value) {

    if (isFull())
        return false;

    if (isEmpty())
        front = rear = 0;
    else
        front = (front - 1 + size) % size;

    arr[front] = value;
    return true;
}

bool insertRear(int value) {

    if (isFull())
        return false;

    if (isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % size;

    arr[rear] = value;
    return true;
}

bool deleteFront() {

    if (isEmpty())
        return false;

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % size;

    return true;
}

bool deleteRear() {

    if (isEmpty())
        return false;

    if (front == rear)
        front = rear = -1;
    else
        rear = (rear - 1 + size) % size;

    return true;
}

int getFront() {

    if (isEmpty())
        return -1;

    return arr[front];
}

int getRear() {

    if (isEmpty())
        return -1;

    return arr[rear];
}

void display() {

    if (isEmpty()) {
        cout << "Deque is Empty\n";
        return;
    }

    cout << "Deque : ";

    int i = front;

    while (true) {

        cout << arr[i] << " ";

        if (i == rear)
            break;

        i = (i + 1) % size;
    }

    cout << endl;
}

int main() {

    cout << "Enter Size : ";
    cin >> size;

    arr = new int[size];

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

    cout << "Front : " << getFront() << endl;
    cout << "Rear  : " << getRear() << endl;

    delete[] arr;

    return 0;
}
