#include<iostream>
#include<vector>
using namespace std;

void findTriplet(vector<int>& arr, int target){

    int n = arr.size();

    for(int i = 0; i < n; i++){

        for(int j = i + 1; j < n; j++){

            for(int k = j + 1; k < n; k++){

                if(arr[i] + arr[j] + arr[k] == target){

                    cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                }
            }
        }
    }
}

int main(){

    vector<int> arr = {1, 4, 45, 6, 10, 8};
    int target = 22;

    findTriplet(arr, target);
}
