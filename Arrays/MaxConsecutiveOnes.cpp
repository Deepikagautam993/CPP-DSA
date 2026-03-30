#include <iostream>
using namespace std;

int maxConsecutiveOnes(int arr[], int n) {

    int count = 0;
    int maxCount = 0;

    for(int i = 0; i < n; i++) {

        if(arr[i] == 1) {
            count++;
        }
        else {
            count = 0;
        }

        if(count > maxCount) {
            maxCount = count;
        }
    }

    return maxCount;
}

int main() {

    int arr[] = {1,1,0,1,1,1};

    int n = 6;

    int result = maxConsecutiveOnes(arr, n);

    cout << "Maximum consecutive ones: "
         << result;

}
