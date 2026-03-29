#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool isValid(vector<int>& window, vector<int>& target) {
    
    for(int i = 0; i < 128; i++) {
        if(window[i] < target[i])
            return false;
    }
    
    return true;
}

string minWindow(string s, string t) {

    vector<int> target(128, 0);

    // Count characters of t
    for(int i = 0; i < t.size(); i++) {
        target[t[i]]++;
    }

    int minLen = INT_MAX;
    string result = "";

    for(int i = 0; i < s.size(); i++) {

        vector<int> window(128, 0);

        for(int j = i; j < s.size(); j++) {

            window[s[j]]++;

            if(isValid(window, target)) {

                int len = j - i + 1;

                if(len < minLen) {
                    minLen = len;
                    result = s.substr(i, len);
                }

                break;
            }
        }
    }

    return result;
}

int main() {

    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << minWindow(s, t);
}
