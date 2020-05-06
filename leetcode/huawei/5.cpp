#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int minTime(vector<int>& time, int m) {
        int n = time.size();
        if (n <= m) return 0;

        // 求前缀和
        preSum.resize(n);
        preSum[0] = time[0];
        for (int i = 1; i < n; i++) {
            preSum[i] = preSum[i - 1] + time[i];
        }

        // 求当前及剩余元素的最大值
        maxVal.resize(n);
        maxVal[n - 1] = time[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxVal[i] = max(maxVal[i + 1], time[i]);
        }

        vector<vector<int>> mm(time.size() + 1, vector<int>(m + 1, -1));
        return dfs(time, m, 0, mm);
    }

   private:
    vector<int> preSum;
    vector<int> maxVal;

    int dfs(vector<int>& time, int m, int begin, vector<vector<int>>& mm) {
        // 如果还剩1道题目或者没有题目了
        if (begin >= time.size()) return 0;

        // 如果剩余的题目数小于等于剩余的天数
        if (time.size() - begin <= m) {
            return 0;
        }

        // 查找缓存
        if (mm[begin][m] != -1) {
            return mm[begin][m];
        }

        // 如果还剩1天
        if (m == 1) {
            mm[begin][m] = preSum[time.size() - 1] - preSum[begin] +
                           time[begin] - maxVal[begin];
            return mm[begin][m];
        }

        int ans = INT_MAX;
        int sum = 0;      // 累加和
        int maxTime = 0;  // 最大值
        for (int i = begin; i < time.size(); i++) {
            if (time.size() - begin <= m) break;

            sum += time[i];
            maxTime = max(maxTime, time[i]);

            int todayMax = sum - maxTime;
            int nextMax = dfs(time, m - 1, i + 1, mm);
            int thisMax = max(todayMax, nextMax);  // 本轮的最大值
            ans = min(ans, thisMax);
        }
        cout << begin << " " << m << " " << ans << endl;
        mm[begin][m] = ans;
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums(10000);
    for (int i = 0; i < 10000; i++) {
        nums[i] = 1;
    }
    cout << s.minTime(nums, 20);
}