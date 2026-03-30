#include<iostream>
#include<vector>
using namespace std;

// TWO POINTERS
void reverseArray(vector<int>& arr){
	int left = 0;
	int right = arr.size() - 1;
	
	while(left < right){
		swap(arr[left], arr[right]);
		left++;
		right--;
	}
}

int main(){
	vector<int> arr = {1,2,3,4};
    reverseArray(arr);
    
    // print array
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}
