#include <iostream>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int>& heights) {

    int n = heights.size();
    int maxArea = 0;

    for(int i = 0; i < n; i++) {

        int height = heights[i];

        int left = i;
        int right = i;

        // Move left
        while(left >= 0 && heights[left] >= height) {
            left--;
        }

        // Move right
        while(right < n && heights[right] >= height) {
            right++;
        }

        int width = right - left - 1;
        int area = height * width;

        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {

    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << largestRectangleArea(heights);

}
