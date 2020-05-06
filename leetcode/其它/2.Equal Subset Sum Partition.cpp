#include <algorithm>
#include <iostream>

using namespace std;

bool canPartition(int *num, int n) {
    // 求sum
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += num[i];
    }

    // 初步判断
    if (sum % 2 != 0) {
        return false;
    }

    sum /= 2;

    bool dp[n][sum + 1];

    // 第一列的都可以
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    //第一行的相等的可以
    for (int i = 1; i <= sum; i++) {
        dp[0][i] = (num[0] == i ? true : false);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (dp[i - 1][j]) {
                dp[i][j] = dp[i - 1][j];
            } else if (j >= num[i]) {
                dp[i][j] = dp[i - 1][j - num[i]];
            }
        }
    }

    return dp[n - 1][sum];
}

int main() {
    int num[] = {1, 2, 3, 4};
    cout << canPartition(num, 4) << endl;

    int num1[] = {1, 1, 3, 4, 7};
    cout << canPartition(num1, 5) << endl;

    int num2[] = {2, 3, 4, 6};
    cout << canPartition(num2, 4) << endl;
}
