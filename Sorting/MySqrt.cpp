#include<iostream>
using namespace std;

int mySqrt(int x) {
    int low = 0;
    int high = x;
    int ans = 0;

    while(low <= high) {

        long long mid = low + (high - low) / 2;

        if(mid * mid <= x) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
	int x = 8;
	cout << mySqrt(x) << endl;
}

