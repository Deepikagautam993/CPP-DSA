#include <iostream>
#include <vector>
using namespace std;

bool printOneSubsequence(int arr[],
                         int size,
                         int index,
                         vector<int>& ds,
                         int sum,
                         int target) {

    // Base Case
    if(index == size) {

        if(sum == target) {

            for(int val : ds)
                cout << val << " ";

            cout << endl;

            return true;
        }

        return false;
    }

    // TAKE
    ds.push_back(arr[index]);

    sum += arr[index];

    if(printOneSubsequence(arr,
                           size,
                           index + 1,
                           ds,
                           sum,
                           target) == true) {

        return true;
    }

    // BACKTRACK
    sum -= arr[index];

    ds.pop_back();

    // SKIP
    if(printOneSubsequence(arr,
                           size,
                           index + 1,
                           ds,
                           sum,
                           target) == true) {

        return true;
    }

    return false;
}

int main() {

    int arr[] = {1,2,1};

    int size = 3;

    vector<int> ds;

    printOneSubsequence(arr,
                        size,
                        0,
                        ds,
                        0,
                        2);

    return 0;
}
