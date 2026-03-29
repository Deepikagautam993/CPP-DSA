#include <iostream>
using namespace std;

int largestRectangle(int matrix[][5], int rows, int cols) {

    int maxArea = 0;

    // Top-left corner
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {

            // Agar starting cell 1 hai
            if(matrix[i][j] == 1) {

                // bottom row
                for(int k = i; k < rows; k++) {

                    // right column
                    for(int l = j; l < cols; l++) {

                        bool allOnes = true;

                        // rectangle check
                        for(int x = i; x <= k; x++) {
                            for(int y = j; y <= l; y++) {

                                if(matrix[x][y] == 0) {
                                    allOnes = false;
                                    break;
                                }
                            }

                            if(!allOnes)
                                break;
                        }

                        if(allOnes) {

                            int area =
                                (k - i + 1) *
                                (l - j + 1);

                            if(area > maxArea)
                                maxArea = area;
                        }
                    }
                }
            }
        }
    }

    return maxArea;
}

int main() {

    int matrix[4][5] = {
        {1,0,1,0,0},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0}
    };

    int result =
        largestRectangle(matrix, 4, 5);

    cout << "Largest rectangle area: "
         << result;

}
