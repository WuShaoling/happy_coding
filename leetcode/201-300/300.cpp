#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> tails(nums.size(), 0);
    int res = 0;
    for (int num : nums) {
        int left = 0, right = res, mid;
        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (tails[mid] < num) {
                left = mid + 1;
            } else if (tails[mid] > num) {
                right = mid;
            } else if (tails[mid] == num) {
                right = mid;
            }
        }
        tails[left] = num;
        if (right == res) res++;
    }
    return res;
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