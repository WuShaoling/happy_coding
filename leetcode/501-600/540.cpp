#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (mid % 2 == 1)  //防止mid是奇数，是的话则左移一位
                mid--;

            if (nums[mid] == nums[mid + 1])  //说明目标数在[mid+2,h]
                l = mid + 2;
            else  //否则目标数在[l,mid]
                h = mid;
        }
        return nums[l];
    }
    // int singleNonDuplicate(vector<int>& nums) {
    //     int n = nums.size();
    //     int left = 0, right = n - 1;
    //     while (left <= right) {
    //         int mid = (left + right) / 2;
    //         if (mid == 0 || mid == n - 1) {
    //             return nums[mid];
    //         } else if (nums[mid] != nums[mid - 1] &&
    //                    nums[mid] != nums[mid + 1]) {
    //             return nums[mid];
    //         }

    //         if (mid & 1) {  // 如果mid是奇数，那么
    //             if (nums[mid] == nums[mid - 1]) {
    //                 left = mid + 1;
    //             } else {
    //                 right = mid - 1;
    //             }
    //         } else {  // 如果mid是偶数
    //             if (nums[mid] == nums[mid + 1]) {
    //                 left = mid + 2;
    //             } else {
    //                 right = mid;
    //             }
    //         }
    //     }
    //     return nums[left - 1];
    // }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 2};
    cout << s.singleNonDuplicate(nums);
}