#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>>& board,
            int row,
            int col,
            char ch) {

    for(int i = 0; i < 9; i++) {

        // Row check
        if(board[row][i] == ch)
            return false;

        // Column check
        if(board[i][col] == ch)
            return false;

        // 3x3 box check
        if(board[
            3 * (row / 3) + i / 3]
            [
            3 * (col / 3) + i % 3
            ] == ch)

            return false;
    }

    return true;
}

bool solve(vector<vector<char>>& board) {

    for(int row = 0;
        row < 9;
        row++) {

        for(int col = 0;
            col < 9;
            col++) {

            // Empty cell found
            if(board[row][col] == '.') {

                // Try digits
                for(char ch = '1';
                    ch <= '9';
                    ch++) {

                    if(isSafe(board,
                              row,
                              col,
                              ch)) {

                        // PLACE
                        board[row][col] = ch;

                        // Recursive Call
                        if(solve(board))
                            return true;

                        // BACKTRACK
                        board[row][col] = '.';
                    }
                }

                return false;
            }
        }
    }

    return true;
}

int main() {

    vector<vector<char>> board = {

        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solve(board);

    // Print solved board
    for(auto row : board) {

        for(char ch : row)
            cout << ch << " ";

        cout << endl;
    }

    return 0;
}
