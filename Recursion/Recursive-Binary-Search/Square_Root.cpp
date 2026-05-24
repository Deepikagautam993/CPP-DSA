#include <iostream>
using namespace std;

void squareRoot(int start,
                int end,
                int n,
                int &ans) {

    // Base Case
    if(start > end)
        return;

    long long mid =
    start + (end - start) / 2;

    long long square = mid * mid;

    // Exact Answer
    if(square == n) {

        ans = mid;
        return;
    }

    // Valid Answer
    if(square < n) {

        ans = mid;

        squareRoot(mid + 1,
                   end,
                   n,
                   ans);
    }

    // Too Large
    else {

        squareRoot(start,
                   mid - 1,
                   n,
                   ans);
    }
}

int main() {

    int n = 20;

    int ans = -1;

    squareRoot(0,
               n,
               n,
               ans);

    cout << ans;

    return 0;
}
