#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
   public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;

        res = 0;
        mergeSort(nums, 0, nums.size() - 1);
        return res;
    }

   private:
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }

    // 0
    //   i
    // 1 3 5 7
    // 2 4 6 8
    //   j
    void merge(vector<int>& nums, int left, int mid, int right) {
        int i, j, k;

        i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            if (nums[i] > 2LL * nums[j]) {
                res += mid - i + 1;
                j++;
            } else {
                i++;
            }
        }

        vector<int> sort_nums(right - left + 1);
        i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                sort_nums[k++] = nums[i++];
            } else {
                sort_nums[k++] = nums[j++];
            }
        }
        while (i <= mid) sort_nums[k++] = nums[i++];
        while (j <= right) sort_nums[k++] = nums[j++];
        for (int m = 0, n = left; m < sort_nums.size(); m++, n++) {
            nums[n] = sort_nums[m];
        }
    }

    int res;
};

int main() {}