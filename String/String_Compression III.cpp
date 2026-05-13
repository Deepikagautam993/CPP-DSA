#include <iostream>
using namespace std;

string compressedString(string word) {

    string ans = "";

    int i = 0;

    while(i < word.size()) {

        char current = word[i];

        int count = 0;

        while(i < word.size() &&
              word[i] == current &&
              count < 9) {

            count++;
            i++;
        }

        ans += to_string(count);
        ans += current;
    }

    return ans;
}

int main() {

    string word = "aaaaaaaaaaaaaabb";

    cout << compressedString(word);

    return 0;
}
