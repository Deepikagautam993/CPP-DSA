#include <iostream>
#include <vector>
using namespace std;

void commonElements(vector<int>& arr1, vector<int>& arr2) {

    for(int i = 0; i < arr1.size(); i++) {

        for(int j = 0; j < arr2.size(); j++) {

            if(arr1[i] == arr2[j]) {
                cout << arr1[i] << " ";
            }

        }

    }
}

int main() {

    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {3, 4, 5, 6, 7};

    commonElements(arr1, arr2);
}
