#include <iostream>
#include <vector>
using namespace std;

double findMedian(vector<int>& a, vector<int>& b) {

    vector<int> arr;

    // Copy first array
    for(int i = 0; i < a.size(); i++) {
        arr.push_back(a[i]);
    }

    // Copy second array
    for(int i = 0; i < b.size(); i++) {
        arr.push_back(b[i]);
    }

    int n = arr.size();

    // Since arrays are already sorted,
    // combined array will also be sorted in this simple case
    if(n % 2 == 1) {
        return arr[n / 2];
    }
    else {
        return (arr[n/2] + arr[n/2 - 1]) / 2.0;
    }
}

int main() {

    vector<int> a = {1, 3};
    vector<int> b = {2, 4};

    double median = findMedian(a, b);

    cout << "Median is: " << median;

    return 0;
}
