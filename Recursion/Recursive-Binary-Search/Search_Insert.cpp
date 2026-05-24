#include <iostream>
using namespace std;

void searchInsert(int arr[],
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
        return;
    }

    // Move LEFT
    if(target < arr[mid]) {

        ans = mid;

        searchInsert(arr,
                     start,
                     mid - 1,
                     target,
                     ans);
    }

    // Move RIGHT
    else {

        searchInsert(arr,
                     mid + 1,
                     end,
                     target,
                     ans);
    }
}

int main() {

    int arr[] = {1,3,5,6};
    int size = 4;

    int target = 2;

    int ans = size;

    searchInsert(arr,
                 0,
                 size - 1,
                 target,
                 ans);

    cout << ans;

    return 0;
}
