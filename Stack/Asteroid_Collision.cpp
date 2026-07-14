#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids)
{
    stack<int> st;

    for(int asteroid : asteroids)
    {
        bool destroyed = false;

        while(!st.empty() &&
              st.top() > 0 &&
              asteroid < 0)
        {
            if(abs(st.top()) > abs(asteroid))
            {
                destroyed = true;
                break;
            }
            else if(abs(st.top()) == abs(asteroid))
            {
                st.pop();
                destroyed = true;
                break;
            }
            else
            {
                st.pop();
            }
        }

        if(!destroyed)
        {
            st.push(asteroid);
        }
    }

    vector<int> ans;

    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector<int> asteroids = {5, 10, -5};

    vector<int> ans = asteroidCollision(asteroids);

    cout << "Remaining Asteroids: ";

    for(int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
