#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> revealCards(vector<int> deck)
{
    sort(deck.begin(), deck.end());

    int n = deck.size();

    vector<int> ans(n);

    queue<int> q;

    // Store indices
    for(int i = 0; i < n; i++)
    {
        q.push(i);
    }

    // Place cards
    for(int i = 0; i < n; i++)
    {
        int index = q.front();
        q.pop();

        ans[index] = deck[i];

        if(!q.empty())
        {
            q.push(q.front());
            q.pop();
        }
    }

    return ans;
}

int main()
{
    vector<int> deck = {17, 13, 11, 2, 3, 5, 7};

    vector<int> ans = revealCards(deck);

    cout << "Final Deck: ";

    for(int card : ans)
    {
        cout << card << " ";
    }

    cout << endl;

    return 0;
}
