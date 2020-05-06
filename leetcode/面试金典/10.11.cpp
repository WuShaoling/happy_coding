#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() == 0) return;
        for (int i = 1; i < nums.size(); i++) {
            if (((i & 1) == 1 && nums[i] < nums[i - 1]) ||
                ((i & 1) == 0 && nums[i] > nums[i - 1])) {
                swap(nums[i], nums[i - 1]);
            }
        }
        // vector<int> t(nums);
        // sort(t.begin(), t.end(), std::greater<int>());
        // int idx = 0, i = 0, j = nums.size() - 1;
        // for (; i < j; i++, j--) {
        //     nums[idx++] = t[i];
        //     nums[idx++] = t[j];
        // }
        // if (i == j) nums[idx] = t[i];
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    s.wiggleSort(nums);
    for (int i : nums) {
        cout << i << " ";
    }
}
// 0 1 2 3
// 1 9 8