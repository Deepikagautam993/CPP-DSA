#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProduct(vector<int>& arr){

    int n = arr.size();
    int maxProduct = INT_MIN;

    for(int i = 0; i < n; i++){

        int product = 1;

        for(int j = i; j < n; j++){

            product = product * arr[j];

            if(product > maxProduct){
                maxProduct = product;
            }
        }
    }

    return maxProduct;
}

int main(){

    vector<int> arr = {2, 3, -2, 4};

    cout << maxProduct(arr);
}
