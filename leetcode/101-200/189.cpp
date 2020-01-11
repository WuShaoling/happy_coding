#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {

        string a = "ab";
        string b = "aab";
        cout << (b.find(a) != b.npos) << "--";

        int len = nums.size();

        if (len == 0 || k <= 0) return;
        if (k >= len) k = k % len;
        if (k <= 0) return;

        // 交换前后 k 个
        for (int i = 0, j = len - 1; i < k && i < j; i++, j--) {
            swap(nums[i], nums[j]);
        }

        // 前 k 个反转
        for (int i = 0, j = k - 1; i < j; i++, j--) {
            swap(nums[i], nums[j]);
        }

        // 中间 k 个反转
        for (int i = k, j = len - k - 1; i < j; i++, j--) {
            swap(nums[i], nums[j]);
        }

        // 后面 len - k 个反转
        for (int i = k, j = len - 1; i < j; i++, j--) {
            swap(nums[i], nums[j]);
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    s.rotate(nums, 2);
    for (int i : nums) cout << i << " ";
    cout << endl;
}