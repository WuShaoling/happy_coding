#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) return res;
        res = vector<int>(nums.size(), 0);

        vector<pair<int, int>> pnums(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            pnums[i] = make_pair(nums[i], i);
        }
        mergeSort(pnums, 0, nums.size() - 1);
        return res;
    }

   private:
    void mergeSort(vector<pair<int, int>>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }
    // i   m  j
    // 1 3 5  2 4 6
    void merge(vector<pair<int, int>>& nums, int left, int mid, int right) {
        int i = left, j = mid + 1, k = 0;
        vector<pair<int, int>> sort_nums(right - left + 1);

        while (i <= mid && j <= right) {
            if (nums[i].first <= nums[j].first) {
                res[nums[i].second] += j - mid - 1;
                sort_nums[k++] = nums[i++];
            } else {
                sort_nums[k++] = nums[j++];
            }
        }

        while (i <= mid) {
            res[nums[i].second] += j - mid - 1;
            sort_nums[k++] = nums[i++];
        }
        while (j <= right) {
            sort_nums[k++] = nums[j++];
        }
        for (int m = 0, n = left; m < sort_nums.size(); m++, n++) {
            nums[n] = sort_nums[m];
        }
    }

    vector<int> res;
};

int main() {
    Solution s;
    vector<int> v = {1, 2, 7, 8, 5};
    vector<int> res = s.countSmaller(v);
    for (int i : res) cout << i << ' ';
}