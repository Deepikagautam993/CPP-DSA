#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> st;

    // Step 1: Queue -> Stack
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }

    // Step 2: Stack -> Queue
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
}

void display(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
}

int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Original Queue : ";
    display(q);

    reverseQueue(q);

    cout << "Reversed Queue : ";
    display(q);

    return 0;
}
