#include<iostream>
#include<vector>
using namespace std;

int singleElement(vector<int>& arr,int n){
	
	for(int i=0; i<arr.size(); i++){
		
		int count = 0;
		
		for(int j=0; j<arr.size(); j++){
			if(arr[i] == arr[j]){
				count++;
			}
		}
		if(count == 1){
			return arr[i];
		}
	}
	return -1;
}

int main(){
	vector<int> arr = {2,3,5,4,4,3,5};
	int n = 7;
	
	cout << singleElement(arr,n) << endl;
}
