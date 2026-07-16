#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseFirstK(queue<int> &q, int k)
{
    if (q.empty() || k <= 0 || k > q.size())
        return;

    stack<int> st;

    // Step 1
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    // Step 2
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    // Step 3
    int remaining = q.size() - k;

    for (int i = 0; i < remaining; i++)
    {
        q.push(q.front());
        q.pop();
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
    q.push(60);
    q.push(70);

    cout << "Original Queue : ";
    display(q);

    reverseFirstK(q, 4);

    cout << "Modified Queue : ";
    display(q);

    return 0;
}
