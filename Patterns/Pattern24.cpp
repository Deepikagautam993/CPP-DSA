#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int i = 1;
	while(i <= n){
		int j = 1, space = 1;
		while(space <= 5 - i){
			cout << " " ;
			space++;
	   }
	   while(j <= i){
	   	cout << j << " ";
	   	j++;
	   }
	   j = i-1;
	   while(j <= 1){
	   	cout << j << " ";
	   	j = j-1;
	   }
	   i = i+1;
	   cout << endl;
	}
}
