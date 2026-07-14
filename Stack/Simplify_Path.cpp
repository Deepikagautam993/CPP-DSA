#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

string simplifyPath(string path)
{
    stack<string> st;
    string token = "";

    for(int i = 0; i <= path.length(); i++)
    {
        if(i == path.length() || path[i] == '/')
        {
            if(token == "" || token == ".")
            {
                // Ignore
            }
            else if(token == "..")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(token);
            }

            token = "";
        }
        else
        {
            token += path[i];
        }
    }

    if(st.empty())
    {
        return "/";
    }

    vector<string> folders;

    while(!st.empty())
    {
        folders.push_back(st.top());
        st.pop();
    }

    reverse(folders.begin(), folders.end());

    string ans = "";

    for(string folder : folders)
    {
        ans += "/" + folder;
    }

    return ans;
}

int main()
{
    string path = "/a/./b/../../c/";

    cout << simplifyPath(path);

    return 0;
}
