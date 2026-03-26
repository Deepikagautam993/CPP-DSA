#include <iostream>
#include <vector>
using namespace std;

void subarraySum(vector<int>& arr, int target) {

    int n = arr.size();

    for(int i = 0; i < n; i++) {

        int sum = 0;

        for(int j = i; j < n; j++) {

            sum += arr[j];

            if(sum == target) {
                cout << "Subarray found from "
                     << i << " to " << j;
                return;
            }

        }

    }

    cout << "No subarray found";
}

int main(){
	vector<int> arr = {1, 4, 20, 3, 10, 5};
	int target = 33;
	
	subarraySum(arr,target);
}
