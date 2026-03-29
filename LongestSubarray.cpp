#include <iostream>
using namespace std;

int longestSubarray(int arr[], int n, int k) {

    int maxLength = 0;

    // starting index
    for(int i = 0; i < n; i++) {

        int sum = 0;

        // ending index
        for(int j = i; j < n; j++) {

            sum += arr[j];

            // divisible check
            if(sum % k == 0) {

                int length = j - i + 1;

                if(length > maxLength) {
                    maxLength = length;
                }
            }
        }
    }

    return maxLength;
}

int main() {

    int arr[] = {2, 7, 6, 1, 4, 5};

    int n = 6;

    int k = 3;

    int result = longestSubarray(arr, n, k);

    cout << "Longest length: " << result;

}
