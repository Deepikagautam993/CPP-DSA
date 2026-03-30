#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& arr, int n){
	
	for(int i=0; i<arr.size(); i++){
		
		int count = 0;
		
		for(int j=0; j<arr.size(); j++){
			
			if(arr[i] == arr[j]){
				count++;
			}
		}
		if(count > n/2){
			return arr[i];
		}
	}
	return -1;
}

int main(){
	vector<int> arr = {2,2,2,1,1,1,2,2};
	int n = 8;
	
	cout << majorityElement(arr,n) << endl;
}
