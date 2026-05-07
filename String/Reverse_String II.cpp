#include <iostream>
#include <string>
using namespace std;

string reverseStr(string s, int k) {

    for(int i = 0; i < s.size(); i += 2 * k) {

        int left = i;
        int right = min(i + k - 1, (int)s.size() - 1);

        while(left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    return s;
}

int main() {

    string s = "abcdefg";
    int k = 2;

    cout << reverseStr(s, k);

    return 0;
}
