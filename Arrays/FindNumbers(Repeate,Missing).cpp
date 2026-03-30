#include <iostream>
#include <vector>
using namespace std;

void findNumbers(vector<int>& arr) {

    int n = arr.size();

    for(int i = 1; i <= n; i++) {

        int count = 0;

        for(int j = 0; j < n; j++) {

            if(arr[j] == i) {
                count++;
            }

        }

        if(count == 0) {
            cout << "Missing: " << i << endl;
        }

        if(count > 1) {
            cout << "Repeating: " << i << endl;
        }

    }
}

int main(){
	vector<int> arr = {4, 3, 6, 2, 1, 1};
	int n = 6;
	
	findNumbers(arr);	
}
