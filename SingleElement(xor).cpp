#include<iostream>
#include<vector>
using namespace std;

int singleElement(vector<int>& arr,int n){
	
	int result = 0;
	
	for(int i=0; i<arr.size(); i++){
		result = result ^ arr[i];
	}
	return result;
}

int main(){
	vector<int> arr = {2,3,5,4,5,3,4};
	int n = 7;
	
	cout << singleElement(arr,n) << endl;
}
