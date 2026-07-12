#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;

    
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top Element : " << st.top() << endl;

    cout << "Size : " << st.size() << endl;

    cout << "Is Empty : " << st.empty() << endl;

    st.pop();

    cout << "After Pop Top : " << st.top() << endl;

    cout << "Size : " << st.size() << endl;

    return 0;
}
