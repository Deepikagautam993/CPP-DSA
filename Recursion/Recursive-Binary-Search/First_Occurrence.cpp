#include <iostream>
using namespace std;

void firstOccurrence(int arr[],
                     int start,
                     int end,
                     int target,
                     int &ans) {

    // Base Case
    if(start > end)
        return;

    int mid = start + (end - start) / 2;

    // Found
    if(arr[mid] == target) {

        ans = mid;

        // Search LEFT
        firstOccurrence(arr,
                        start,
                        mid - 1,
                        target,
                        ans);
    }

    // LEFT HALF
    else if(target < arr[mid]) {

        firstOccurrence(arr,
                        start,
                        mid - 1,
                        target,
                        ans);
    }

    // RIGHT HALF
    else {

        firstOccurrence(arr,
                        mid + 1,
                        end,
                        target,
                        ans);
    }
}

int main() {

    int arr[] = {1,2,2,2,3,4};
    int size = 6;

    int target = 2;

    int ans = -1;

    firstOccurrence(arr,
                    0,
                    size - 1,
                    target,
                    ans);

    cout << ans;

    return 0;
}
