#include <iostream>
#include <vector>
using namespace std;

void splitEqualSum(vector<int>& arr) {

    int n = arr.size();

    for(int i = 0; i < n - 1; i++) {

        int leftSum = 0;
        int rightSum = 0;

        // Left sum
        for(int j = 0; j <= i; j++) {
            leftSum += arr[j];
        }

        // Right sum
        for(int j = i + 1; j < n; j++) {
            rightSum += arr[j];
        }

        if(leftSum == rightSum) {
            cout << "Array can be split at index: " << i << endl;
            return;
        }
    }

    cout << "Cannot split into equal sum subarrays";
}

int main() {

    vector<int> arr = {1, 2, 3, 3};

    splitEqualSum(arr);

}
