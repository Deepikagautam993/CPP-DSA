#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxCircularSum(vector<int>& arr){

    int n = arr.size();
    int maxSum = INT_MIN;

    for(int i = 0; i < n; i++){

        int currentSum = 0;

        for(int j = 0; j < n; j++){

            int index = (i + j) % n;

            currentSum += arr[index];

            maxSum = max(maxSum, currentSum);
        }
    }

    return maxSum;
}

int main(){

    vector<int> arr = {5, -3, 5};

    cout << maxCircularSum(arr);
}
