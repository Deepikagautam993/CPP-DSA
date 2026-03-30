#include<iostream>
#include<vector>
using namespace std;

int equilibriumIndex(vector<int>& arr, int n){
	
	for(int i=0; i<arr.size(); i++){
		
		int leftSum = 0;
	    int rightSum = 0;
	    
	    for(int j=0; j<i; j++){
	    	leftSum += arr[j];
		}
		
		for(int j=i+1; j<arr.size(); j++){
			rightSum += arr[j];
		}
		
		if(leftSum == rightSum){
			return i;
		}
	}
	return -1;
}

int main(){
	vector<int> arr = {-7, 1, 5, 2, -4, 3, 0};
	int n = 7;
	
	cout << equilibriumIndex(arr,n) << endl;
}
