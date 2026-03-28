#include<iostream>
#include<vector>
using namespace std;

int firstMissingPositive(vector<int>& nums){

    int n = nums.size();

    for(int i = 1; i <= n + 1; i++){

        bool found = false;

        for(int j = 0; j < n; j++){

            if(nums[j] == i){
                found = true;
                break;
            }
        }

        if(!found){
            return i;
        }
    }

    return -1;
}

int main(){

    vector<int> nums = {3, 4, -1, 1};

    cout << firstMissingPositive(nums);
}
