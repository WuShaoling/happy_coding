#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) return -1;

        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }

        fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[fast];
            if (fast == slow) break;
        }

        return slow;
    }
    // int findDuplicate(vector<int>& nums) {
    //     if (nums.empty()) return -1;

    //     int left = 1, right = nums.size() - 1;
    //     while (left < right) {
    //         int mid = left + (right - left) / 2;

    //         int count = 0;
    //         for (int num : nums) {
    //             if (num <= mid) count++;
    //         }

    //         // 根据抽屉原理，小于等于 4 的数的个数如果严格大于 4 个，
    //         // 此时重复元素一定出现在 [1, 4] 区间里
    //         if (count > mid) {
    //             right = mid;
    //         } else {
    //             left = mid + 1;
    //         }
    //     }
    //     return left;
    // }
};

int main() {}