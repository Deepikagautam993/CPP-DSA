#include <iostream>
#include <vector>
using namespace std;

void splitEqualSumOptimal(vector<int>& arr) {

    int totalSum = 0;

    for(int i = 0; i < arr.size(); i++) {
        totalSum += arr[i];
    }

    int leftSum = 0;

    for(int i = 0; i < arr.size() - 1; i++) {

        leftSum += arr[i];

        int rightSum = totalSum - leftSum;

        if(leftSum == rightSum) {
            cout << "Array can be split at index: " << i << endl;
            return;
        }
    }

    cout << "Cannot split into equal sum subarrays";
}

int main() {

    vector<int> arr = {2, 4, 2};

    splitEqualSumOptimal(arr);

}
