#include <iostream>
using namespace std;

bool isSorted(int arr[],
              int size,
              int index) {

    // Base Case
    if(index == size - 1)
        return true;

    // Self Work
    if(arr[index] > arr[index + 1])
        return false;

    // Recursive Call
    return isSorted(arr,
                    size,
                    index + 1);
}

int main() {

    int arr[] = {1, 2, 3, 4};
    int size = 4;

    if(isSorted(arr, size, 0))
        cout << "Sorted";
    else
        cout << "Not Sorted";

    return 0;
}
