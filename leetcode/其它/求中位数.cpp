#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int i = left, j = right;
    int flag = nums[left];
    while (i < j) {
        while (i < j && nums[j] >= flag) j--;
        while (i < j && nums[i] <= flag) i++;
        if (i < j) swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[left]);
    return i;
}

int findPos(vector<int>& nums, int left, int right, int target) {
    while (left <= right) {
        int p = partition(nums, left, right);
        if (p == target) {
            return nums[p];
        } else if (p < target) {
            left = p + 1;
        } else {
            right = p - 1;
        }
    }
    return 0;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    if (nums.size() % 2 == 1) {
        cout << findPos(nums, 0, nums.size() - 1, (nums.size() - 1) / 2);
    } else {
        int left = findPos(nums, 0, nums.size() - 1, (nums.size() - 1) / 2);
        int right =
            findPos(nums, 0, nums.size() - 1, (nums.size() - 1) / 2 + 1);
        cout << left << " " << right << endl;
    }
}

// 0 1 2 3 4
// 1 2 3 4 5 6