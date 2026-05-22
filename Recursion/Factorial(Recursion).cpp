#include <iostream>
using namespace std;

int factorial(int n) {

    // Base Case
    if(n == 0 || n == 1)
        return 1;

    // Recursive Relation
    return n * factorial(n - 1);
}

int main() {

    int n = 5;

    cout << factorial(n);

    return 0;
}
