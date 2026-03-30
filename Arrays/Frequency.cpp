#include<iostream>
#include<vector>
using namespace std;

void frequency(vector<int>& arr){

    for(int i = 0; i < arr.size(); i++){

        // check if already counted
        bool visited = false;

        for(int k = 0; k < i; k++){
            if(arr[i] == arr[k]){
                visited = true;
                break;
            }
        }

        if(visited)
            continue;

        int count = 0;

        for(int j = 0; j < arr.size(); j++){
            if(arr[i] == arr[j])
                count++;
        }

        cout << arr[i] << " -> " << count << endl;
    }
}

int main(){

    vector<int> arr = {1,2,2,3,1};

    frequency(arr);

}
