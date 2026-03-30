#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minJumps(vector<int>& arr, int index) {

    int n = arr.size();

    // If reached last index
    if(index >= n - 1)
        return 0;

    // If element is 0, cannot move
    if(arr[index] == 0)
        return INT_MAX;

    int minSteps = INT_MAX;

    // Try all possible jumps
    for(int step = 1; step <= arr[index]; step++) {

        int jumps = minJumps(arr, index + step);

        if(jumps != INT_MAX) {
            minSteps = min(minSteps, jumps + 1);
        }
    }

    return minSteps;
}

int main() {

    vector<int> arr = {2, 3, 1, 1, 4};

    int result = minJumps(arr, 0);

    cout << result;
}
