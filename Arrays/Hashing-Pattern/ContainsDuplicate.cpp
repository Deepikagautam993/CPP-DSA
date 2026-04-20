#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int nums[] = {1, 2, 3, 1};
    int n = 4;

    unordered_set<int> s;

    for(int i = 0; i < n; i++) {
        if(s.find(nums[i]) != s.end()) {
            cout << "Duplicate Found";
            return 0;
        }
        s.insert(nums[i]);
    }

    cout << "No Duplicate";
}
