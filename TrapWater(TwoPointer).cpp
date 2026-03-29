#include<iostream>
#include<vector>
using namespace std;

int trapWater(vector<int>& height){
	int left = 0;
    int right = height.size() - 1;

    int leftMax = 0;
    int rightMax = 0;

    int totalWater = 0;

    while (left < right) {

        if (height[left] <= height[right]) {

            if (height[left] >= leftMax)
                leftMax = height[left];
                else
                    totalWater += leftMax - height[left];

                    left++;
		}
		else {

            if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    totalWater += rightMax - height[right];

                right--;
            }
    } 

    return totalWater;
}

int main(){
	vector<int> height = {3, 0, 2, 0, 4};
    cout << "Total trapped water: " << trapWater(height);
}
