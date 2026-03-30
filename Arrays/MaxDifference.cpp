#include <iostream>
#include <vector>
using namespace std;

void maxDifference(vector<int>& arr) {

    int n = arr.size();
    int maxDiff = arr[1] - arr[0];

    for(int i = 0; i < n; i++) {

        for(int j = i + 1; j < n; j++) {

            if(arr[j] - arr[i] > maxDiff) {
                maxDiff = arr[j] - arr[i];
            }

        }

    }

    cout << "Maximum Difference = "
         << maxDiff;
}

int main(){
	vector<int> arr = {7, 1, 5, 3, 6, 4};
	maxDifference(arr);
}
