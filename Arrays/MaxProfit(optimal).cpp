#include<iostream>
#include<vector>
using namespace std;

void maxProfit(vector<int>& prices){

    int minPrice = prices[0];
    int maxProfit = 0;

    for(int i = 1; i < prices.size(); i++){

        int profit = prices[i] - minPrice;

        if(profit > maxProfit){
            maxProfit = profit;
        }

        if(prices[i] < minPrice){
            minPrice = prices[i];
        }
    }

    cout << "Maximum Profit: " << maxProfit;
}

int main(){

    vector<int> prices = {7,1,5,3,6,4};

    maxProfit(prices);
}
