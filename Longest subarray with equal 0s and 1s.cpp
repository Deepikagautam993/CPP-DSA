#include<iostream>
#include<vector>
using namespace std;

int longestSubarray(vector<int>& arr){

    int n = arr.size();
    int maxLength = 0;

    for(int i = 0; i < n; i++){

        int count0 = 0;
        int count1 = 0;

        for(int j = i; j < n; j++){

            if(arr[j] == 0)
                count0++;
            else
                count1++;

            if(count0 == count1){
                int length = j - i + 1;
                maxLength = max(maxLength, length);
            }
        }
    }

    return maxLength;
}

int main(){

    vector<int> arr = {0,1,0,0,1,1,0};

    cout << longestSubarray(arr);
}
