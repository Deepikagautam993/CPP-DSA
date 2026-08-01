#include <iostream>
#include <vector>
using namespace std;

vector<string> ans;

void solve(string digits, int index, string output,
           vector<string>& mapping)
{
    if(index == digits.length())
    {
        if(output.length() > 0)
            ans.push_back(output);

        return;
    }

    int number = digits[index] - '0';
    string value = mapping[number];

    for(int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);

        solve(digits, index + 1, output, mapping);

        output.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> mapping = {
        "", "",
        "abc", "def",
        "ghi", "jkl",
        "mno", "pqrs",
        "tuv", "wxyz"
    };

    string output = "";

    solve(digits, 0, output, mapping);

    return ans;
}

int main()
{
    string digits = "23";

    vector<string> result = letterCombinations(digits);

    for(string s : result)
    {
        cout << s << " ";
    }

    return 0;
}
