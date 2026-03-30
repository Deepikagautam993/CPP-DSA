#include<iostream>
#include<vector>
using namespace std;

void rearrange(vector<int>& arr){
	
	vector<int> pos;
	vector<int> neg;
	
	for(int i=0; i<arr.size(); i++){
		if(arr[i] >= 0){
			pos.push_back(arr[i]);
		}
		else{
			neg.push_back(arr[i]);
		}
	}
	int i=0, p=0, n=0;
	
	while(p < pos.size() && n < pos.size()){
		arr[i++] = pos[p++];
		arr[i++] = neg[n++];
	}
}

int main(){
	vector<int> arr = {1,2,-4,-5};
	
	rearrange(arr);
	
	for(int x : arr){
		cout << x << " ";
	}
}
