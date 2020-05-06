#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return {};

        vector<int> res;
        deque<int> q;

        for (int i = 0; i < nums.size(); i++) {
            // 删除过期的
            if (!q.empty() && q.front() < i - k + 1) q.pop_front();

            // 单调队列
            while (!q.empty() && nums[i] > nums[q.back()]) q.pop_back();
            q.push_back(i);

            if (i >= k - 1) res.push_back(nums[q.front()]);
        }

        return res;
    }
};

int main() {
    vector<int> v = {9, 10, 9, -7, -4, -8, 2, -6};
    Solution s;
    vector<int> res = s.maxSlidingWindow(v, 5);
    for (int i : res) cout << i << ' ';
}