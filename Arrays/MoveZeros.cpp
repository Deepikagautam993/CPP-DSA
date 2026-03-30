#include<iostream>
#include<vector>
using namespace std;

void moveZeros(vector<int>& arr){
	
	vector<int> temp;
	
//	STORE NONO-ZERO ELEMENTS
	for(int i=0; i<arr.size(); i++){
		if(arr[i] != 0){
			temp.push_back(arr[i]);
		}
	}
	
//	COUNT ZERO
    int zero = arr.size() - temp.size();
    
//    ADD ZERO AT END
    for(int i=0; i<zero; i++){
    	temp.push_back(0);
	}
	
//	COPY BACK TO ORIGINAL ARRAY
    for(int i=0; i<arr.size(); i++){
    	arr[i] = temp[i];
	}
}

int main(){
	vector<int> arr = {0,2,0,5,15};
	moveZeros(arr);
	
	for(int num : arr){
		cout << num << " ";
	}
	return 0;
}
