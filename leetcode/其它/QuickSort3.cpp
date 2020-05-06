#include <iostream>
#include <vector>

using namespace std;

void q_sort(vector<int>& nums, int left, int right) {
    if (left < right) {
        int lt = left;
        int i = left;
        int gt = right;
        int v = nums[left];

        while (i <= gt) {
            if (nums[i] < v) {
                swap(nums[i], nums[lt]);
                i++;
                lt++;
            } else if (nums[i] == v) {
                i++;
            } else {
                swap(nums[i], nums[gt]);
                gt--;
            }
        }
        q_sort(nums, left, lt - 1);
        q_sort(nums, gt + 1, right);
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 3, 3, 4, 4, 5};
    reverse(nums.begin(), nums.end());
    q_sort(nums, 0, nums.size() - 1);
    for (int i : nums) cout << i << " ";
}
/*
  l     r
3 4 1 8 2 6 5 7
    i
4
*/