#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        int target = nums.size() - k;  // 第k大元素的索引

        while (left <= right) {
            int index = partition(nums, left, right);
            if (index == target) {
                return nums[index];
            } else if (index < target) {
                left = index + 1;
            } else {
                right = index - 1;
            }
        }
        return -1;
    }

    int partition(vector<int>& nums, int left, int right) {
        if (left >= right) return left;
        int i = left;
        int j = right;
        int v = nums[left];
        while (i < j) {
            while (i < j && nums[j] >= v) j--;
            while (i < j && nums[i] <= v) i++;
            if (i < j) swap(nums[i], nums[j]);
        }
        swap(nums[i], nums[left]);
        return left;
    }
};

int main() {}