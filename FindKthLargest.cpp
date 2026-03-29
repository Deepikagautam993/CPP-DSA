#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findKthLargest(vector<int>& arr, int k) {

    int n = arr.size();

    int currentMax = INT_MAX;

    for(int i = 0; i < k; i++) {

        int maxVal = INT_MIN;

        for(int j = 0; j < n; j++) {

            if(arr[j] > maxVal && arr[j] < currentMax) {
                maxVal = arr[j];
            }
        }

        currentMax = maxVal;
    }

    return currentMax;
}

int main() {

    vector<int> arr = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << findKthLargest(arr, k);
}
