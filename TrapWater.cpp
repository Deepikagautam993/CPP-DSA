#include <iostream>
#include <vector>
using namespace std;

int trapWater(vector<int>& height) {
    int n = height.size();
    int totalWater = 0;

    for(int i = 0; i < n; i++) {

        int leftMax = 0;
        int rightMax = 0;

        // Find left maximum
        for(int j = 0; j <= i; j++) {
            leftMax = max(leftMax, height[j]);
        }

        // Find right maximum
        for(int j = i; j < n; j++) {
            rightMax = max(rightMax, height[j]);
        }

        int water = min(leftMax, rightMax) - height[i];
        totalWater += water;
    }

    return totalWater;
}

int main() {
    vector<int> height = {3, 0, 2, 0, 4};
    cout << "Total trapped water: "
         << trapWater(height);
}
