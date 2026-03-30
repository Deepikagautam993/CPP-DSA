#include<iostream>
#include<vector>
using namespace std;

int findMissing(vector<int>& arr, int n){
	for(int i=1; i<=n; i++){
		
		bool found = false;
		for(int j=0; j<arr.size(); j++){
			if(arr[j] == i){
				found = true;
				break;
			}
		}
		if(found == false){
			return i;
		}
	}
}

int main(){
	vector<int> arr = {1,2,4,5};
	int n = 5;
	
	cout << findMissing(arr,n) << endl;
}
