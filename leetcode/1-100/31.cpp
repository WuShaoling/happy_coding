#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // 1. 从右往左找到第一个相邻升序数对
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // 2. 在 [j,end) 从后向前查找第一个满足 A[i] < A[k] 的 k
            int k = n - 1;
            while (k >= 0 && nums[i] >= nums[k]) {
                k--;
            }
            swap(nums[i], nums[k]);
        }

        // 3. 逆置 [j,end)
        for (int a = i + 1, b = n - 1; a < b; a++, b--) {
            swap(nums[a], nums[b]);
        }
    }
};

int main() {}