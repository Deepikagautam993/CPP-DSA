#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count frequency of each character
        unordered_map<char, int> freq;
        for(char c : s) {
            freq[c]++;
        }

        // Step 2: Put characters in a vector
        vector<pair<char, int>> charFreq(freq.begin(), freq.end());

        // Step 3: Sort by frequency in descending order
        sort(charFreq.begin(), charFreq.end(), [](pair<char,int> &a, pair<char,int> &b) {
            return a.second > b.second; // higher frequency first
        });

        // Step 4: Build the result string
        string result;
        for(auto &p : charFreq) {
            result += string(p.second, p.first);
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s = "tree";
    cout << sol.frequencySort(s) << endl;
    return 0;
}
