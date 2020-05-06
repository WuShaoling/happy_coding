#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        int left_bound = -1, right_bound = -1, left, right;

        left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {  // 在右边
                left = mid + 1;
            } else if (nums[mid] > target) {  // 在左边
                right = mid - 1;
            } else if (nums[mid] == target) {  // 找到了，尝试找左边界
                left_bound = mid;
                right = mid - 1;
            }
        }

        left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {  // 在右边
                left = mid + 1;
            } else if (nums[mid] > target) {  // 在左边
                right = mid - 1;
            } else if (nums[mid] == target) {  // 找到了，尝试找右边界
                right_bound = mid;
                left = mid + 1;
            }
        }
        if (left_bound == -1 && right_bound == -1) return 0;
        return right_bound - left_bound + 1;
    }
};

int main() {
    Solution s;
    vector<int> v = {1, 2, 3};
    cout << s.search(v, 1);
}