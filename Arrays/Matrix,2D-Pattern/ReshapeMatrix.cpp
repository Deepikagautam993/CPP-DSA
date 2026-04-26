#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

    int m = mat.size();
    int n = mat[0].size();

    if(m * n != r * c) {
        return mat;
    }

    vector<vector<int>> ans(r, vector<int>(c));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {

            int index = i * n + j;

            int newRow = index / c;
            int newCol = index % c;

            ans[newRow][newCol] = mat[i][j];
        }
    }

    return ans;
}

int main() {

    vector<vector<int>> mat = {
        {1, 2},
        {3, 4}
    };

    int r = 1, c = 4;

    vector<vector<int>> result = matrixReshape(mat, r, c);

    for(auto row : result) {
        for(auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
