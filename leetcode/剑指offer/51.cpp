#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int reversePairs(vector<int>& nums) {
        res = 0;
        merge_sort(nums, 0, nums.size() - 1);
        return res;
    }

   private:
    void merge_sort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = (left + right) / 2;
        merge_sort(nums, left, mid);
        merge_sort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(right - left + 1);

        int i = left, j = mid + 1, idx = 0;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[idx++] = nums[i++];
            } else {
                res += (mid + 1 - i);
                temp[idx++] = nums[j++];
            }
        }
        while (i <= mid) temp[idx++] = nums[i++];
        while (j <= right) temp[idx++] = nums[j++];

        i = left;
        for (int v : temp) nums[i++] = v;
    }

    int res = 0;
};
//  i         j
// (2 3 5 7) (1 4 6 8)
int main() {
    Solution s;
    vector<int> v = {1, 3, 2, 3, 1};
    cout << s.reversePairs(v) << endl;
    for (int i : v) cout << i << " ";
}