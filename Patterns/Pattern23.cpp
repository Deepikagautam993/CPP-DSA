#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int i = 1, num  = 1;
	while(i <= num){
		int j = 1, space = 1;
		while(space <= n - i){
			cout << " " ;
			space++;
	   }
	   while(j <= i){
	   	cout << num << " ";
	   	num++;
	   	j++;
	   }
	}
	i++;
	cout << endl;
}
