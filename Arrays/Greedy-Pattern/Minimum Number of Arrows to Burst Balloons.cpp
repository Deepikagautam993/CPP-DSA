#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    if(points.empty())
        return 0;

    sort(points.begin(), points.end(),
        [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

    int arrows = 1;
    int end = points[0][1];

    for(int i = 1; i < points.size(); i++) {
        if(points[i][0] > end) {
            arrows++;
            end = points[i][1];
        }
    }

    return arrows;
}

int main() {
    vector<vector<int>> points = {
        {10,16},
        {2,8},
        {1,6},
        {7,12}
    };

    int result = findMinArrowShots(points);

    cout << "Minimum arrows needed: " << result;

    return 0;
}
