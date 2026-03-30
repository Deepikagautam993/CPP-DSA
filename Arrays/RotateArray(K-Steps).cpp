#include<iostream>
#include<vector>
using namespace std;

void rotateArray(vector<int>&arr, int k){
	
	int n = arr.size();
	
	for(int step = 0; step < k; step++){
		
		int last = arr[n-1];
		
		for(int i=n-1; i>0; i--){
			arr[i] = arr[i-1];
		}
		arr[0] = last;
	}
}

int main(){
	vector<int> arr = {1,2,3,4,5,6,7};
	int k = 3;
	
	rotateArray(arr,k);
	
	for(int num : arr){
		cout << num << " ";
	}
	return 0;
}
