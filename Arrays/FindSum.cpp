#include<iostream>
#include<vector>
using namespace std;

int findSum(vector<int>& arr,int n){
	
	int sum = 0;
	for(int i=0; i<arr.size(); i++){
		sum = sum+arr[i];
	}
	return sum;
}

int main(){
	vector<int> arr = {2,4,6,9,5};
	int n = 5;
	cout << findSum(arr,n) << endl;
}
