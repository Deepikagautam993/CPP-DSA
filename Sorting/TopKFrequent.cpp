#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    vector<pair<int,int>> freq;

    int count = 1;

    for(int i = 1; i < nums.size(); i++) {

        if(nums[i] == nums[i-1]) {
                count++;
        }
        else {
            freq.push_back({nums[i-1], count});
            count = 1;
        }
    }

    // last element
    freq.push_back({nums[nums.size()-1], count});

    // sort by frequency
    sort(freq.begin(), freq.end(),
        [](pair<int,int>& a, pair<int,int>& b) {
            return a.second > b.second;
    });

    vector<int> result;

    for(int i = 0; i < k; i++) {
        result.push_back(freq[i].first);
    }

    return result;
}

int main(){
	vector<int> nums = {1,1,1,2,2,3};
	int k = 2;
	
	vector<int> ans = topKFrequent(nums,k);
	for(int num : ans){
		cout << num << " ";
	}	
}
