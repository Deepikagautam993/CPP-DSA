#include <iostream>
using namespace std;

bool isPalindrome(string &str,
                  int left,
                  int right) {

    // Base Case
    if(left >= right)
        return true;

    // Self Work
    if(str[left] != str[right])
        return false;

    // Recursive Call
    return isPalindrome(str, left + 1, right - 1);
}

int main() {

    string str = "madam";

    if(isPalindrome(str, 0, str.length() - 1))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}
