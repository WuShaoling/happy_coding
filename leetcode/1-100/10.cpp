#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isMatchFromTailToHead1(string s, string p) {
    int m = s.size(), n = p.size();
    // 这里dp矩阵是要大一圈的，用来处理s或者p为空串的情况，矩阵的行标i对应s的i-1，矩阵的列标j对应p的j-1
    bool dp[m + 1][n + 1];
    // s和p都是空串的时候自然true
    dp[0][0] = true;
    // 初始化首列
    for (int i = 1; i <= m; i++) {
        dp[i][0] = false;
    }
    // 初始化首行
    dp[0][1] = false;
    for (int j = 2; j <= n; j++) {
        if (p[j - 1] != '*')
            dp[0][j] = false;
        else
            dp[0][j] = dp[0][j - 2];
    }
    // ""
    // "...*"
    // 0    1     2    3     4
    // true false false false true
    // 通过递推公式开始填充矩阵
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] != '*') {
                dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '.') &&
                           dp[i - 1][j - 1];
            } else {
                if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                    // abcccc
                    //  abc*
                    // abc
                    // abc*
                    // abc
                    // abcc*
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                    if (j > 1) dp[i][j] = dp[i][j] || dp[i][j - 2];
                } else {
                    dp[i][j] = dp[i][j - 2]; //   abc
                                             // abcb* 
                }
            }
        }
    }
    return dp[m][n];
}

int main() {}