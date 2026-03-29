#include<iostream>
#include<vector>
using namespace std;

string minWindow(string s, string t) {

        vector<int> freq(128, 0);

        // Count characters of t
        for(char c : t)
            freq[c]++;

        int left = 0;
        int right = 0;
        int count = t.size();

        int minLen = INT_MAX;
        int start = 0;

        while(right < s.size()) {

            // Expand window
            if(freq[s[right]] > 0)
                count--;

            freq[s[right]]--;
            right++;

            // Valid window
            while(count == 0) {

                if(right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                freq[s[left]]++;

                if(freq[s[left]] > 0)
                    count++;

                left++;
            }
        }

        if(minLen == INT_MAX)
        return "";

    return s.substr(start, minLen);
}

int main(){
	string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << minWindow(s, t);
}
