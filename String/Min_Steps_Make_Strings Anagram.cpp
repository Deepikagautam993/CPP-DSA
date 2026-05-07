#include <iostream>
#include <vector>
using namespace std;

int minSteps(string s, string t) {

    vector<int> freq(26, 0);

    for(int i = 0; i < s.size(); i++) {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    int steps = 0;

    for(int count : freq) {
        if(count > 0) {
            steps += count;
        }
    }

    return steps;
}

int main() {

    string s = "bab";
    string t = "aba";

    cout << minSteps(s, t);

    return 0;
}
