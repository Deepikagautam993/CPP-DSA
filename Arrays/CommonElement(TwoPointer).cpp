#include <iostream>
#include <vector>
using namespace std;

void commonElements(vector<int>& arr1, vector<int>& arr2) {

    int i = 0, j = 0;

    while(i < arr1.size() && j < arr2.size()) {

        if(arr1[i] == arr2[j]) {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }

    }
}

int main() {

    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {3, 4, 5, 6, 7};

    commonElements(arr1, arr2);
}
