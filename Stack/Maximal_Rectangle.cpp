#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights)
{
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();

    for(int i = 0; i <= n; i++)
    {
        while(!st.empty() && (i == n || heights[st.top()] >= heights[i]))
        {
            int height = heights[st.top()];
            st.pop();

            int width;

            if(st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            maxArea = max(maxArea, height * width);
        }

        st.push(i);
    }

    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix)
{
    if(matrix.empty())
        return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> heights(cols, 0);

    int maxArea = 0;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(matrix[i][j] == '1')
                heights[j]++;
            else
                heights[j] = 0;
        }

        maxArea = max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
}

int main()
{
    vector<vector<char>> matrix =
    {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    cout << "Maximum Rectangle Area = " << maximalRectangle(matrix);

    return 0;
}
