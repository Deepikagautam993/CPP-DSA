#include <iostream>
using namespace std;

int countSubarrays(int arr[], int n, int k) {

    int count = 0;

    // starting index
    for(int i = 0; i < n; i++) {

        int xr = 0;

        // ending index
        for(int j = i; j < n; j++) {

            xr = xr ^ arr[j];

            if(xr == k) {
                count++;
            }
        }
    }

    return count;
}

int main() {

    int arr[] = {4, 2, 2, 6, 4};

    int n = 5;

    int k = 6;

    int result =
        countSubarrays(arr, n, k);

    cout << "Number of subarrays: "
         << result;

}
