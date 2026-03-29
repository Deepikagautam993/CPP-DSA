#include <iostream>
using namespace std;

int maxSumRectangle(int matrix[][3], int rows, int cols) {

    int maxSum = -100000;

    // top row
    for(int top = 0; top < rows; top++) {

        // bottom row
        for(int bottom = top; bottom < rows; bottom++) {

            // left column
            for(int left = 0; left < cols; left++) {

                // right column
                for(int right = left; right < cols; right++) {

                    int sum = 0;

                    // rectangle ka sum
                    for(int i = top; i <= bottom; i++) {
                        for(int j = left; j <= right; j++) {
                            sum += matrix[i][j];
                        }
                    }

                    if(sum > maxSum) {
                        maxSum = sum;
                    }
                }
            }
        }
    }

    return maxSum;
}

int main() {

    int matrix[3][3] = {
        {1, 2, -1},
        {-3, 4, 5},
        {2, -6, 3}
    };

    int result = maxSumRectangle(matrix, 3, 3);

    cout << "Maximum Sum Rectangle: "
         << result;

}
