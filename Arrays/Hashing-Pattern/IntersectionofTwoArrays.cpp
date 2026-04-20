#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> result;

    for(int num : nums2) {
        if(set1.count(num)) {
            result.insert(num);
        }
    }

    return vector<int>(result.begin(), result.end());
}

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> ans = intersection(nums1, nums2);

    cout << "Intersection: ";
    for(int num : ans) {
        cout << num << " ";
    }

    return 0;
}
