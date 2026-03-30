#include <iostream>
using namespace std;

double maxAverage(int arr[], int n, int k) {

    double maxAvg = -100000;   // very small value

    // Har starting index try karo
    for(int i = 0; i <= n - k; i++) {

        int sum = 0;

        // k elements ka sum
        for(int j = i; j < i + k; j++) {
            sum += arr[j];
        }

        double avg = (double)sum / k;

        if(avg > maxAvg) {
            maxAvg = avg;
        }
    }

    return maxAvg;
}

int main() {

    int arr[] = {1, 12, -5, -6, 50, 3};

    int n = 6;
    int k = 4;

    double result = maxAverage(arr, n, k);

    cout << "Maximum Average: " << result;

}
