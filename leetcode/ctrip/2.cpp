#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

int climb(int n) {
    if (n < 0) return -1;
    if (n == 0) return 0;
    if (n == 0 || n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;
    vector<vector<long>> dp(n + 1, vector<long>(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 1;
    dp[1][1] = 0;
    dp[2][0] = 2;
    dp[2][1] = 0;

    for (int i = 3; i < n + 1; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1] + dp[i - 3][0];
    }
    long ans = dp[n][0] + dp[n][1];
    if (ans > 2147483647 || ans < 0) return -1;
    return (int)ans;
}

int main() {
    int res;

    int _n;
    cin >> _n;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    res = climb(_n);
    cout << res << endl;

    return 0;
}
