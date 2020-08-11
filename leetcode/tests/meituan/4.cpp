#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int> nums) {
    if (nums.size() <= 1) return nums.size();

    int n = nums.size();
    vector<int> left(n + 1, 1);
    vector<int> right(n + 1, 1);
    left[0] = 0;
    right[n] = 0;

    int leftInx = 2;
    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) {
            left[leftInx] = left[leftInx - 1] + 1;
        }
        leftInx++;
    }

    int rightIdx = n - 2;
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            right[rightIdx] = right[rightIdx + 1] + 1;
        }
        rightIdx--;
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, left[i]);
        res = max(res, right[i + 1]);
        if (nums[i - 1] < nums[i + 1]) res = max(res, left[i] + right[i + 1]);
    }

    return res == 0 ? 1 : res;
}

int main() {
    int n, t;

    cin >> n;
    if (n == 0) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << lengthOfLIS(nums);
}