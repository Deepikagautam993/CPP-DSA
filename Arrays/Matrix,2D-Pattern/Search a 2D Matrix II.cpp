#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int m = matrix.size();
    int n = matrix[0].size();

    int row = 0;
    int col = n - 1;

    while(row < m && col >= 0) {

        if(matrix[row][col] == target) {
            return true;
        }
        else if(matrix[row][col] > target) {
            col--;
        }
        else {
            row++;
        }
    }

    return false;
}

int main() {

    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    int target = 5;

    cout << searchMatrix(matrix, target);

    return 0;
}
