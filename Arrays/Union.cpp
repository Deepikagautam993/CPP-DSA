#include<iostream>
#include<vector>
using namespace std;

void unionArray(vector<int>& a, vector<int>& b){
    
    // Step 1: print all elements of a
    for(int i=0; i<a.size(); i++){
        cout << a[i] << " ";
    }

    // Step 2: check elements of b
    for(int j=0; j<b.size(); j++){
        
        bool found = false;

        for(int i=0; i<a.size(); i++){
            
            if(b[j] == a[i]){
                found = true;
                break;
            }
        }

        // Step 3: if not found, print
        if(found == false){
            cout << b[j] << " ";
        }
    }
}

int main(){

    vector<int> a = {1,2,3};
    vector<int> b = {2,3,4};

    unionArray(a,b);
}
