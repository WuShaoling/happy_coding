#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int sums[n];
        sums[0] = nums[0];
        for (int i = 1; i < n; i++) sums[i] = sums[i - 1] + nums[i];
        if (sums[n - 1] < s) return 0;

        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            // sums[k] - sums[i] + nums[i] >= s;
            // sums[k] >= s + sums[i] - nums[i];
            int k = bSearch(i, n - 1, sums, s + sums[i] - nums[i]);
            cout << i << " " << k << " " << endl;
            if (k != -1) res = min(res, k - i + 1);
        }

        return res == INT_MAX ? 0 : res;
    }

    int bSearch(int left, int right, int sums[], int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (sums[mid] == target) return mid;
            if (target < sums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return sums[left] > target ? left : -1;
    }
};

int main() {
    Solution s;
    vector<int> v = {1, 0, 1, 0, 0, 1};
    cout << s.minSubArrayLen(2, v);
}
/*
  i
      j
0 1 2 3  4
1 2 3 4  5
1 3 6 10 15

sums[j] - sums[i] + nums[i]
*/
