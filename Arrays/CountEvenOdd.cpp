#include<iostream>
#include<vector>
using namespace std;

void countEvenOdd(vector<int>& arr,int n){
	
	int evenCount = 0;
	int oddCount = 0;
	
	for(int i=0; i<arr.size(); i++){
		if(arr[i] % 2 == 0){
			evenCount++;
		}
		else{
			oddCount++;
		}
	}
	cout << "Even numbers " << evenCount << endl;
	cout << "Odd numbers " << oddCount << endl;
}

int main(){
	vector<int> arr = {1,2,3,4,5,6};
	int n = 6;
	
	countEvenOdd(arr,n);
}
