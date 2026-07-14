#include <iostream>
#include <stack>
using namespace std;

class StockSpanner
{
private:
    stack<pair<int,int>> st;

public:

    int next(int price)
    {
        int span = 1;

        while(!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});

        return span;
    }
};

int main()
{
    StockSpanner obj;

    cout << obj.next(100) << endl;
    cout << obj.next(80) << endl;
    cout << obj.next(60) << endl;
    cout << obj.next(70) << endl;
    cout << obj.next(60) << endl;
    cout << obj.next(75) << endl;
    cout << obj.next(85) << endl;

    return 0;
}
