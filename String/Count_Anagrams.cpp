#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

const long long MOD = 1e9 + 7;

long long power(long long a, long long b) {

    long long ans = 1;

    while(b > 0) {

        if(b % 2 == 1) {
            ans = (ans * a) % MOD;
        }

        a = (a * a) % MOD;

        b /= 2;
    }

    return ans;
}

long long factorial(int n) {

    long long ans = 1;

    for(int i = 1; i <= n; i++) {
        ans = (ans * i) % MOD;
    }

    return ans;
}

int countAnagrams(string s) {

    stringstream ss(s);

    string word;

    long long result = 1;

    while(ss >> word) {

        vector<int> freq(26, 0);

        for(char ch : word) {
            freq[ch - 'a']++;
        }

        long long ways = factorial(word.size());

        for(int count : freq) {

            if(count > 1) {

                long long denom = factorial(count);

                ways = (ways * power(denom, MOD - 2)) % MOD;
            }
        }

        result = (result * ways) % MOD;
    }

    return result;
}

int main() {

    string s = "too hot";

    cout << countAnagrams(s);

    return 0;
}
