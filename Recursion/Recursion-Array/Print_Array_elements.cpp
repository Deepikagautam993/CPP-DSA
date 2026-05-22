#include<iostream>
using namespace std;

void printArray(int arr[], int size, int index){
	
//	BASE CASE 
    if(index == size)
    return;
    
//    PRINT CURRENT ELEMENT
    cout << arr[index] << " ";
    
//    MOVE NEXT INDEX
    printArray(arr, size, index + 1);
}

int main(){
	
	int arr[] = {10,20,30,40};
	int index = 0;
	int size = 4;
	
	printArray(arr, size, 0);
	
	return 0;
}
