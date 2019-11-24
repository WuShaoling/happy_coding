//
// Created by 吴绍岭 on 2019-04-13.
//

#include <iostream>
#include <algorithm>

using namespace std;

int zeroOnePackage(int profits[], int weights[], int n, int capacity) {
    int dp[n][capacity + 1];

    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }
    for (int c = 1; c <= capacity; c++) {
        if (weights[0] <= c) {
            dp[0][c] = weights[0];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int c = 1; c <= capacity; c++) {
            if (weights[i] > c) {
                dp[i][c] = dp[i - 1][c];
            } else {
                dp[i][c] = max(dp[i - 1][c], profits[i] + dp[i - 1][c - weights[i]]);
            }
        }
    }

    return dp[n - 1][capacity];
}

int zeroOnePackage1(int profits[], int weights[], int n, int capacity) {
    int dp[capacity + 1];

    for (int c = 0; c <= capacity; c++) {
        if (weights[0] <= c) {
            dp[c] = weights[0];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int c = capacity; c >= 0; c--) {
            if (weights[i] <= c) {
                dp[c] = max(dp[c], profits[i] + dp[c - weights[i]]);
            }
        }
    }

    return dp[capacity];
}


int main() {
    int profits[] = {1, 6, 10, 16};
    int weights[] = {1, 2, 3, 5};
    cout << zeroOnePackage1(profits, weights, 4, 7);
}