#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int minDistance(string word1, string word2) {
        int m = word1.size() + 1;
        int n = word2.size() + 1;

        int dp[n];
        for (int i = 1; i < n; i++) dp[i] = i;

        for (int i = 1; i < m; i++) {
            int pre = dp[0];
            for (int j = 1; j < n; j++) {
                int temp = dp[j];
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = pre;
                } else {
                    // dp[i-1][j-1] 表示替换操作
                    // dp[i-1][j] 表示删除操作
                    // dp[i][j-1] 表示插入操作。
                    // 以 word1 为 "horse"，word2 为 "ros"，且 dp[5][3] 为例，
                    // 即要将 word1的前 5 个字符转换为 word2的前 3 个字符，也就是将 horse 转换为 ros，
                    // 因此有： 
                    // (1) dp[i-1][j-1]，即先将 word1 的前 4 个字符 hors 转换为 word2 的前 2 个字符 ro，
                    //      然后将第五个字符 word1[4]（因为下标基数以 0 开始） 由 e 替换为 s（即替换为 word2 的第三个字符，word2[2]） 
                    // (2) dp[i][j-1]，即先将 word1 的前 5 个字符 horse 转换为 word2 的前 2 个字符 ro，
                    //      然后在末尾补充一个 s，即插入操作 
                    // (3) dp[i-1][j]，即先将 word1 的前 4 个字符 hors 转换为 word2 的前 3 个字符 ros，
                    //      然后删除 word1 的第 5 个字符
                    int m = min(dp[j - 1], dp[j]);
                    m = min(m, pre);
                    dp[j] = m + 1;
                }
                pre = temp;
            }
        }

        return dp[n - 1];
    }
};

int main() {}