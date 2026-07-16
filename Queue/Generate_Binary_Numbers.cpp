#include <iostream>
#include <queue>
#include <string>
using namespace std;

void generateBinary(int n)
{
    queue<string> q;

    q.push("1");

    for (int i = 1; i <= n; i++)
    {
        string current = q.front();
        q.pop();

        cout << current << endl;

        q.push(current + "0");
        q.push(current + "1");
    }
}

int main()
{
    int n = 10;

    generateBinary(n);

    return 0;
}
