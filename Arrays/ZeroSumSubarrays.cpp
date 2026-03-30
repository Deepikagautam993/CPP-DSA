#include <iostream>
#include <vector>
using namespace std;

void zeroSumSubarrays(vector<int>& arr) {

    int n = arr.size();

    for(int i = 0; i < n; i++) {

        int sum = 0;

        for(int j = i; j < n; j++) {

            sum += arr[j];

            if(sum == 0) {
                cout << "Subarray from "
                     << i << " to " << j << endl;
            }

        }

    }
}

int main() {
    vector<int> arr = {6, 3, -1, -3, 4, -2, 2};

    zeroSumSubarrays(arr);
}
