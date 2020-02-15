#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        return max(myRob(nums, 0), myRob(nums, 1));
    }

    int myRob(vector<int>& nums, int offset) {
        int pre = 0;
        int max_v = nums[offset];
        for (int i = 2; i < nums.size(); i++) {
            int temp = max_v;
            max_v = max(max_v, pre + nums[i + offset - 1]);
            pre = temp;
        }
        return max_v;
    }
};

int main() {}