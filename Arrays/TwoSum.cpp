#include<iostream>
#include<vector>
using namespace std;

void twoSum(vector<int>& arr,int target){
	
	for(int i=0; i<arr.size(); i++){
		
		for(int j=i+1; j<arr.size(); j++){
			
			if(arr[i] + arr[j] == target){
				cout << arr[i] << " and " << arr[j] << endl;
				return;
			}
		}
	}
	cout << "No pair found ";
}

int main(){
	vector<int> arr = {2,7,11,15};
	int target = 9;
	
	twoSum(arr,target);
}
