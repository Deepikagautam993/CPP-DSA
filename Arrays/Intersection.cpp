#include<iostream>
#include<vector>
using namespace std;

void intersection(vector<int>& a, vector<int>& b){
	
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<b.size(); j++){
			if(a[i] == b[j])
			cout << a[i] << " ";
		}
	}
}

int main(){
	vector<int> a = {1,2,3};
	vector<int> b = {2,3,4};
	
	intersection(a,b);
}
