#include<iostream>
#include<vector>
#include<deque>
using namespace std;

long long sumOfMaxAndMin(vector<int>& arr,int k)
{
    deque<int> maxDQ;
    deque<int> minDQ;

    long long sum=0;

    for(int i=0;i<arr.size();i++)
    {
        while(!maxDQ.empty() &&
              maxDQ.front()<=i-k)
            maxDQ.pop_front();

        while(!minDQ.empty() &&
              minDQ.front()<=i-k)
            minDQ.pop_front();

        while(!maxDQ.empty() &&
              arr[maxDQ.back()]<=arr[i])
            maxDQ.pop_back();

        while(!minDQ.empty() &&
              arr[minDQ.back()]>=arr[i])
            minDQ.pop_back();

        maxDQ.push_back(i);
        minDQ.push_back(i);

        if(i>=k-1)
        {
            sum += arr[maxDQ.front()];
            sum += arr[minDQ.front()];
        }
    }

    return sum;
}

int main()
{
    vector<int> arr={2,5,-1,7,-3,-1,-2};

    int k=4;

    cout<<sumOfMaxAndMin(arr,k);

    return 0;
}
