#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // if (nums.empty()) return {-1, -1};
        return {lower_bound(nums, target), upper_bound(nums, target)};
    }

   private:
    // 第一次出现的位置，left 的范围是[0, nums.size()]
    int lower_bound(const vector<int>& nums, int target) {
        int left = 0, right = nums.size(), mid;
        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] > target) {  // [left, mid)
                right = mid;
            } else if (nums[mid] < target) {  // [mid+1, right)
                left = mid + 1;
            } else {  // 如果相等，左侧可能还有，继续向左寻找 [left, mid)
                right = mid;
            }
        }
        if (left == nums.size() || nums[left] != target) return -1;
        return left;
    }

    // 求上界，left 的范围是[0, nums.size()]
    int upper_bound(const vector<int>& nums, int target) {
        int left = 0, right = nums.size(), mid;
        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] > target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                left = mid + 1;
            }
        }
        if (left == 0 || nums[left - 1] != target) return -1;
        return left;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> res = s.searchRange(nums, 6);
    cout << res[0] << " " << res[1];
}