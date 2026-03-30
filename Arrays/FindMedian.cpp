#include <iostream>
#include <vector>
using namespace std;

double findMedian(vector<int>& a, vector<int>& b) {

    vector<int> merged;

    int i = 0;
    int j = 0;

    // Merge arrays
    while(i < a.size() && j < b.size()) {

        if(a[i] < b[j]) {
            merged.push_back(a[i]);
            i++;
        }
        else {
            merged.push_back(b[j]);
            j++;
        }
    }

    while(i < a.size()) {
        merged.push_back(a[i]);
        i++;
    }

    while(j < b.size()) {
        merged.push_back(b[j]);
        j++;
    }

    int n = merged.size();

    // Find median
    if(n % 2 == 1) {
        return merged[n / 2];
    }
    else {
        return (merged[n/2] + merged[n/2 - 1]) / 2.0;
    }
}

int main() {

    vector<int> a = {1, 3};
    vector<int> b = {2};

    cout << findMedian(a, b);
}
