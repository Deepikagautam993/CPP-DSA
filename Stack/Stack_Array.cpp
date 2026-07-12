#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int size;

    // Constructor
    Stack(int size)
    {
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    
    void push(int data)
    {
        if(top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        arr[top] = data;
    }

    
    void pop()
    {
        if(top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }

        top--;
    }

    
    int peek()
    {
        if(top == -1)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }

        return arr[top];
    }

    
    bool isEmpty()
    {
        return top == -1;
    }

    
    bool isFull()
    {
        return top == size - 1;
    }
};

int main()
{
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top Element : " << s.peek() << endl;

    s.pop();

    cout << "Top After Pop : " << s.peek() << endl;

    cout << "Is Empty : " << s.isEmpty() << endl;
    cout << "Is Full  : " << s.isFull() << endl;

    return 0;
}
