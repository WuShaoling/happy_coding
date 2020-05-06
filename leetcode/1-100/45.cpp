#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int jump(vector<int>& nums) {
        if (nums.empty()) return 0;

        int ans = 0;
        int end = 0;
        int maxPos = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            maxPos = max(maxPos, i + nums[i]);
            if (i == end) {
                end = maxPos;
                ans++;
            }
        }
        return ans;
    }
};

/*
2 3
*/

int main() {
    Solution s;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << s.jump(nums);
}