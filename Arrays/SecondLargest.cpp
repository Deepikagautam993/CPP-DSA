#include<iostream>
#include<vector>
using namespace std;

int secondLargest(vector<int>& arr){
	
	int largest = arr[0];
	for(int i = 1; i<arr.size(); i++){
		if(arr[i] > largest){
			largest = arr[i];
		}
	}
	
	int secondMax = -1;
	for(int i = 0; i<arr.size(); i++){
		if(arr[i] != largest && arr[i] > secondMax){
			secondMax = arr[i];
		}
	}
	return secondMax;
}

int main(){
    vector<int> arr = {10,5,8,20};
    cout << secondLargest(arr) << endl;
}
