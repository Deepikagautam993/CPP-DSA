#include<iostream>
#include<vector>
using namespace std;

int minJumps(vector<int>& arr) {

    int n = arr.size();

    if(n <= 1)
        return 0;

    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;

    for(int i = 0; i < n - 1; i++) {

        farthest = max(farthest, i + arr[i]);

        if(i == currentEnd) {
            jumps++;
            currentEnd = farthest;
        }
    }

    return jumps;
}

int main() {

    vector<int> arr = {2, 3, 1, 1, 4};

    int result = minJumps(arr);

    cout << result;
}
