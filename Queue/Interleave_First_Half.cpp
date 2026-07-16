#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int> &q)
{
    if (q.size() % 2 != 0)
    {
        cout << "Queue size must be even." << endl;
        return;
    }

    queue<int> firstHalf;

    int half = q.size() / 2;

    // Store first half
    for (int i = 0; i < half; i++)
    {
        firstHalf.push(q.front());
        q.pop();
    }

    // Interleave
    while (!firstHalf.empty())
    {
        q.push(firstHalf.front());
        firstHalf.pop();

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
    q.push(80);

    cout << "Original Queue : ";
    display(q);

    interleave(q);

    cout << "Interleaved Queue : ";
    display(q);

    return 0;
}
