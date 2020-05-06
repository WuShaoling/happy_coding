#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;

        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return true;
            if (nums[low] == nums[mid]) {
                low++;
                continue;
            }
            if (nums[mid] == nums[high]) {
                high--;
                continue;
            }
            if (nums[low] < nums[mid]) {
                if (nums[low] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 2, 1, 1};
    cout << s.search(nums, 2);
}