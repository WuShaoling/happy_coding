#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int index = 0;
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && nums[j] == nums[i]) j++;
            // j即为下一轮 i 的位置
            int end = j - 1;
            if (end - i + 1 > 2) {
                end = i + 1;
            }
            // [i, end] 移到 index 开始的位置
            if (i != index) {
                for (int a = i; a <= end; a++) {
                    nums[index++] = nums[a];
                }
            } else {
                index = end + 1;
            }
            i = j;
        }
        return index;
    }
};

int main() {
    Solution s;
    vector<int> nums = {, 0, 1, 1, 1, 1, 2, 3, 3};
    int res = s.removeDuplicates(nums);
    for (int i = 0; i < res; i++) {
        cout << nums[i] << " ";
    }
}