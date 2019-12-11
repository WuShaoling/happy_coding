#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int S) {
        dfs(nums, 0, S, 0);
        return res;
    }

   private:
    void dfs(vector<int>& nums, int cur, int S, int index) {
        if (index == nums.size()) {
            if (S == cur) res++;
            return;
        }

        dfs(nums, cur + nums[index], S, index + 1);
        dfs(nums, cur - nums[index], S, index + 1);
    }

    int res = 0;
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << s.findTargetSumWays(nums, 3);
}