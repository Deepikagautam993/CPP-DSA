#include<iostream>
#include<vector>
using namespace std;

void findPairs(vector<int>& arr, int target){

    int n = arr.size();

    for(int i = 0; i < n; i++){

        for(int j = i + 1; j < n; j++){

            if(arr[i] + arr[j] == target){

                cout << arr[i] << " and " << arr[j] << endl;
            }
        }
    }
}

int main(){

    vector<int> arr = {1, 5, 7, -1, 5};
    int target = 6;

    findPairs(arr, target);
}
