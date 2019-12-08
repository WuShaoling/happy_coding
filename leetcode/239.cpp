#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;

        if (nums.size() == 0) {
            return ret;
        }

        for (int i = 0; i < nums.size() - k + 1; i++) {
            int max = INT_MIN;
            for (int j = i; j < i + k && j < nums.size(); j++) {
                if (nums[j] > max) max = nums[j];
            }
            ret.push_back(max);
        }

        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-7, -8, 7, 5, 7, 1, 6, 0};
    vector<int> res = solution.maxSlidingWindow(nums, 4);
    for (int i : res) {
        cout << i << " ";
    }
}