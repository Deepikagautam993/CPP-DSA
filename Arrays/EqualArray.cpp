#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool areEqual(vector<int>& arr1, vector<int>& arr2) {

    if(arr1.size() != arr2.size())
        return false;

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    for(int i = 0; i < arr1.size(); i++) {
        if(arr1[i] != arr2[i])
            return false;
    }

    return true;
}

int main() {

    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2 = {4, 3, 2, 1};

    if(areEqual(arr1, arr2))
        cout << "Equal";
    else
        cout << "Not Equal";
}
