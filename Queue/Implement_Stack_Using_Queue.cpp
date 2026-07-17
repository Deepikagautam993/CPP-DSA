#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

void push(int x)
{
    q.push(x);

    int size = q.size();

    // Rotate previous elements
    for(int i = 0; i < size - 1; i++)
    {
        q.push(q.front());
        q.pop();
    }
}


void pop()
{
    if(q.empty())
    {
        cout << "Stack Underflow!" << endl;
        return;
    }

    cout << q.front() << " popped from Stack." << endl;
    q.pop();
}


int top()
{
    if(q.empty())
    {
        cout << "Stack is Empty!" << endl;
        return -1;
    }

    return q.front();
}


bool empty()
{
    return q.empty();
}


void display()
{
    if(q.empty())
    {
        cout << "Stack is Empty!" << endl;
        return;
    }

    queue<int> temp = q;

    cout << "Stack (Top -> Bottom): ";

    while(!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }

    cout << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    cout << "Top : " << top() << endl;

    pop();

    display();

    push(40);

    display();

    cout << "Top : " << top() << endl;

    while(!empty())
    {
        pop();
    }

    return 0;
}
