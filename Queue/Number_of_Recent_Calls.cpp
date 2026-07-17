#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

// Function to process a new request
int ping(int t)
{
    // Add current request
    q.push(t);

    // Remove requests older than (t - 3000)
    while(!q.empty() && q.front() < t - 3000)
    {
        q.pop();
    }

    // Number of valid requests
    return q.size();
}

int main()
{
    cout << "ping(1) = " << ping(1) << endl;
    cout << "ping(100) = " << ping(100) << endl;
    cout << "ping(3001) = " << ping(3001) << endl;
    cout << "ping(3002) = " << ping(3002) << endl;

    return 0;
}
