#include<iostream>
#include<vector>
using namespace std;

void maxProfit(vector<int>& prices){
    int maxProfit = 0;

    for(int i = 0; i < prices.size(); i++){
        for(int j = i + 1; j < prices.size(); j++){

            int profit = prices[j] - prices[i];

            if(profit > maxProfit){
                maxProfit = profit;
            }
        }
    }

    cout << "Maximum Profit: " << maxProfit;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};

    maxProfit(prices);
}
