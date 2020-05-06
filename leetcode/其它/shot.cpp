#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, double> memo;

double backtrack(int n, vector<double>& p, vector<int>& v) {
    // 0 颗子弹
    if (n == 0) {
        return 0;
    }

    // 只有 1 颗子弹
    if (n == 1) {
        return p[0] * v[0];
    }

    double res = 0;
    // 每次选择 i 个子弹
    for (int i = 1; i <= n; i++) {
        // 当前得分
        double curScore = p[i - 1] * v[i - 1];

        // 求剩下子弹的得分
        int leftBullet = n - i;  // 剩下的子弹数
        double nextScore = 0;    // 剩下的子弹的得分
        if (memo.find(leftBullet) !=
            memo.end()) {  // 已经计算过了，直接从map中取结果
            nextScore = memo[leftBullet];
        } else {  // 否则需要计算
            nextScore = backtrack(leftBullet, p, v);
            memo[leftBullet] = nextScore;
        }

        // 更新最大值
        res = max(res, curScore + p[i - 1] * nextScore);
    }

    return res;
}

int main() {
    int n = 2;
    vector<double> p = {0.8, 0.5};
    vector<int> v = {1, 2};
    cout << backtrack(n, p, v) << endl;
}