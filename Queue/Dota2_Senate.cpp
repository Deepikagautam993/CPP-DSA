#include <iostream>
#include <queue>
#include <string>
using namespace std;

string predictPartyVictory(string senate)
{
    queue<int> radiant;
    queue<int> dire;

    int n = senate.size();

    // Store indices
    for(int i = 0; i < n; i++)
    {
        if(senate[i] == 'R')
            radiant.push(i);
        else
            dire.push(i);
    }

    while(!radiant.empty() && !dire.empty())
    {
        int r = radiant.front();
        int d = dire.front();

        radiant.pop();
        dire.pop();

        if(r < d)
        {
            radiant.push(r + n);
        }
        else
        {
            dire.push(d + n);
        }
    }

    if(radiant.empty())
        return "Dire";
    else
        return "Radiant";
}

int main()
{
    string senate;

    cout << "Enter Senate String (R/D): ";
    cin >> senate;

    cout << "Winner : " << predictPartyVictory(senate);

    return 0;
}
