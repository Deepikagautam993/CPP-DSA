#include <iostream>
using namespace std;

int power(int x, int n) {

    // Base Case
    if(n == 0)
        return 1;

    // Recursive Relation
    return x * power(x, n - 1);
}

int main() {

    int x = 2;
    int n = 5;

    cout << power(x, n);

    return 0;
}
