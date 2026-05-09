#include <iostream>
#include <vector>
using namespace std;

vector<int> findAnagrams(string s, string p) {

    vector<int> ans;

    if(p.size() > s.size()) {
        return ans;
    }

    vector<int> pFreq(26, 0);
    vector<int> sFreq(26, 0);

    for(char ch : p) {
        pFreq[ch - 'a']++;
    }

    int windowSize = p.size();

    for(int i = 0; i < s.size(); i++) {

        sFreq[s[i] - 'a']++;

        if(i >= windowSize) {
            sFreq[s[i - windowSize] - 'a']--;
        }

        if(sFreq == pFreq) {
            ans.push_back(i - windowSize + 1);
        }
    }

    return ans;
}

int main() {

    string s = "cbaebabacd";
    string p = "abc";

    vector<int> result = findAnagrams(s, p);

    for(int index : result) {
        cout << index << " ";
    }

    return 0;
}
