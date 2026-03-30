#include <iostream>
using namespace std;

int findPlatforms(int arrival[], int departure[], int n) {

    int maxPlatforms = 1;

    // Har train check karo
    for(int i = 0; i < n; i++) {

        int platforms = 1;

        // Baaki sab trains se compare
        for(int j = i + 1; j < n; j++) {

            if(arrival[i] <= departure[j] &&
               arrival[j] <= departure[i]) {

                platforms++;
            }
        }

        if(platforms > maxPlatforms) {
            maxPlatforms = platforms;
        }
    }

    return maxPlatforms;
}

int main() {

    int arrival[] = {900, 940, 950, 1100, 1500, 1800};

    int departure[] = {910, 1200, 1120, 1130, 1900, 2000};

    int n = 6;

    int result = findPlatforms(arrival, departure, n);

    cout << "Minimum platforms required: "
         << result;

}
