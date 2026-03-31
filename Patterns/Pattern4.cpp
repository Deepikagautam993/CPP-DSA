#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int i = 1;
	int toPrime = 1;
	
	while(i <= n){
		int j = 1;
		
		while(j <= n){
			cout << toPrime << " ";
			toPrime++;
			j++;
		}
		
		cout << endl;
		i++;
	}
	
	return 0;
}
