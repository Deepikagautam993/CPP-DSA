#include <iostream>
#include <vector>
using namespace std;

int countInversions(vector<int>& arr) {

    int n = arr.size();
    int count = 0;

    for(int i = 0; i < n - 1; i++) {

        for(int j = i + 1; j < n; j++) {

            if(arr[i] > arr[j]) {
                count++;
            }
        }
    }

    return count;
}

int main() {

    vector<int> arr = {8, 4, 2, 1};

    cout << countInversions(arr);

}
