#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int canPartition(int *num, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += num[i];

    bool dp[n][sum / 2 + 1];
    memset(dp, 0, sizeof(dp));

    // populate the sum=0 columns, as we can always form '0' sum with an empty
    // set
    for (int i = 0; i < n; i++) dp[i][0] = true;

    // with only one number, we can form a subset only when the required sum is
    // equal to that number
    for (int s = 1; s <= sum / 2; s++) {
        dp[0][s] = (num[0] == s ? true : false);
    }

    // process all subsets for all sums
    for (int i = 1; i < n; i++) {
        for (int s = 1; s <= sum / 2; s++) {
            // if we can get the sum 's' without the number at index 'i'
            if (dp[i - 1][s]) {
                dp[i][s] = dp[i - 1][s];
            } else if (s >= num[i]) {
                // else include the number and see if we can find a subset to
                // get the remaining sum
                dp[i][s] = dp[i - 1][s - num[i]];
            }
        }
    }

    int sum1 = 0;
    // Find the largest index in the last row which is true
    for (int i = sum / 2; i >= 0; i--) {
        if (dp[n - 1][i] == true) {
            sum1 = i;
            break;
        }
    }

    int sum2 = sum - sum1;
    return abs(sum2 - sum1);
}

int main() {
    int num[] = {1, 2, 3, 9};
    cout << canPartition(num, 4) << endl;

    int num1[] = {1, 2, 7, 1, 5};
    cout << canPartition(num1, 5) << endl;

    int num2[] = {1, 3, 100, 4};
    cout << canPartition(num2, 4) << endl;
}
