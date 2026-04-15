#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    queue<int> q;  // store indices of negative numbers

    for (int i = 0; i < arr.size(); i++) {

        // Step 1: push negative index
        if (arr[i] < 0) {
            q.push(i);
        }

        // Step 2: remove out of window index
        if (!q.empty() && q.front() <= i - k) {
            q.pop();
        }

        // Step 3: window formed
        if (i >= k - 1) {
            if (!q.empty()) {
                cout << arr[q.front()] << " ";
            } else {
                cout << 0 << " ";
            }
        }
    }

    return 0;
}
