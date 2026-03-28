#include<iostream>
#include<vector>
using namespace std;

int maxNonAdjacentSum(vector<int>& arr){

    int n = arr.size();
    int maxSum = 0;

    for(int i = 0; i < n; i++){

        int sum = 0;

        for(int j = i; j < n; j += 2){

            sum = sum + arr[j];

        }

        if(sum > maxSum){
            maxSum = sum;
        }
    }

    return maxSum;
}

int main(){

    vector<int> arr = {2, 1, 4, 9};

    cout << maxNonAdjacentSum(arr);
}
