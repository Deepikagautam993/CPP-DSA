#include<iostream>
using namespace std;

int findMissing(int arr[], int n){
	
	int xor1 = 0;
	int xor2 = 0;
	
	for(int i=1; i<=n; i++){
    //	xor1 = xor1 ^ i;
        xor1 ^= i;	 
	}
	
	for(int j=0; j<n-1; j++){
		xor2 ^= arr[j];
	}
	
	return xor1 ^ xor2;
}

int main(){
	int arr[] = {1,2,4,5};
	int n = 5;
	
	cout << findMissing(arr,n) << endl;
}
