#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestSubarray(vector<int>& nums, int limit) {
        // 滑动窗口的最大值和最小值
        // 8 2 4 7
        // 8 7
        deque<int> w_max;
        deque<int> w_min;

        int n = nums.size();

        int ans = 0;
        int i = 0, j = 0;
        while (j < n) {  // 如果可以，一直往后找

            while (!w_max.empty() && nums[j] > nums[w_max.back()])
                w_max.pop_back();
            w_max.push_back(j);

            while (!w_min.empty() && nums[j] < nums[w_min.back()])
                w_min.pop_back();
            w_min.push_back(j);

            int cur_max = nums[w_max.front()];
            int cur_min = nums[w_min.front()];
            while (i <= j && cur_max - cur_min > limit) {
                if (i == w_max.front()) w_max.pop_front();
                if (i == w_min.front()) w_min.pop_front();
                cur_max = nums[w_max.front()];
                cur_min = nums[w_min.front()];
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }
        // 8 2 4 7
        // 2 4 7
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 2, 2, 2, 4, 4, 2, 2};
    cout << s.longestSubarray(nums, 0);
}