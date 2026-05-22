#include <iostream>
using namespace std;

int maxArray(int arr[], int size, int index) {

    // Base Case
    if(index == size - 1)
        return arr[index];

    // Recursive Relation
    return max(arr[index],
               maxArray(arr, size, index + 1));
}

int main() {

    int arr[] = {3, 9, 2, 7, 5};
    int size = 5;

    cout << maxArray(arr, size, 0);

    return 0;
}
