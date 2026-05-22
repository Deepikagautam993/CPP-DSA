#include <iostream>
using namespace std;

int sumArray(int arr[], int size, int index) {

    // Base Case
    if(index == size)
        return 0;

    // Recursive Relation
    return arr[index] + sumArray(arr, size, index + 1);
}

int main() {

    int arr[] = {1, 2, 3, 4};
    int size = 4;

    cout << sumArray(arr, size, 0);

    return 0;
}
