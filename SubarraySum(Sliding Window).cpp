#include <iostream>
#include <vector>
using namespace std;

void subarraySum(vector<int>& arr, int target) {

    int start = 0;
    int sum = 0;

    for(int end = 0; end < arr.size(); end++) {

        sum += arr[end];

        while(sum > target) {
            sum -= arr[start];
            start++;
        }

        if(sum == target) {
            cout << "Subarray found from "
                 << start << " to " << end;
            return;
        }

    }

    cout << "No subarray found";
}

int main(){
	vector<int> arr = {1, 4, 20, 3, 10, 5};
	int target = 33;
	
	subarraySum(arr,target);
}
