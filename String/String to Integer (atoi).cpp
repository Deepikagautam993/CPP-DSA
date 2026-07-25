#include <iostream>
#include <climits>
#include <cctype>
using namespace std;

int myAtoi(string s)
{
    int i = 0;
    int n = s.length();

    // Skip leading spaces
    while (i < n && s[i] == ' ')
        i++;

    // Check sign
    int sign = 1;

    if (i < n && (s[i] == '+' || s[i] == '-'))
    {
        if (s[i] == '-')
            sign = -1;

        i++;
    }

    long long num = 0;

    // Read digits
    while (i < n && isdigit(s[i]))
    {
        num = num * 10 + (s[i] - '0');

        // Overflow Check
        if (sign * num >= INT_MAX)
            return INT_MAX;

        if (sign * num <= INT_MIN)
            return INT_MIN;

        i++;
    }

    return sign * num;
}

int main()
{
    string s = "   -42";

    cout << myAtoi(s);

    return 0;
}
