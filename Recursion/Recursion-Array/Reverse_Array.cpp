#include <iostream>
using namespace std;

void reverseArray(int arr[],
                  int left,
                  int right) {

    // Base Case
    if(left >= right)
        return;

    // Self Work
    swap(arr[left], arr[right]);

    // Recursive Call
    reverseArray(arr,
                 left + 1,
                 right - 1);
}

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;

    reverseArray(arr, 0, size - 1);

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
