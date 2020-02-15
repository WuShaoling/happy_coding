#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;

        for (int i = 0; i < nums.size(); i++) {
            // 移除过期的数据
            if (!q.empty() && i - k + 1 > q.front()) {
                q.pop_front();
            }

            // 删除小的元素
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }

            q.push_back(i);

            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};

int main() {
