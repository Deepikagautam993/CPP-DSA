#include <iostream>
#include <algorithm>
using namespace std;

void findDuplicates(int arr[], int n) {
    
    // Step 1: Sort array
    sort(arr, arr + n);

    // Step 2: Check adjacent elements
    for(int i = 1; i < n; i++) {
        
        if(arr[i] == arr[i - 1]) {
            cout << arr[i] << " ";
        }
    }
}

int main() {
    
    int arr[] = {4, 2, 7, 2, 5, 4};
    int n = 6;

    findDuplicates(arr, n);

    return 0;
}
