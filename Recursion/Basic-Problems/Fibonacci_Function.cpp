#include <iostream>
using namespace std;

int fib(int n) {

    // Base Case
    if(n == 0 || n == 1)
        return n;

    // Recursive Relation
    return fib(n - 1) + fib(n - 2);
}

int main() {

    int n = 5;

    cout << fib(n);

    return 0;
}
