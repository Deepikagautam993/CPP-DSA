#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    int buy1 = INT_MAX;
    int profit1 = 0;

    int buy2 = INT_MAX;
    int profit2 = 0;

    for (int price : prices) {

        // First buy
        buy1 = min(buy1, price);

        // First sell
        profit1 = max(profit1, price - buy1);

        // Second buy (effective price)
        buy2 = min(buy2, price - profit1);

        // Second sell
        profit2 = max(profit2, price - buy2);
    }

    cout << "Maximum Profit: " << profit2;

    return 0;
}
