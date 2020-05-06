#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] & 1) cnt++;
                if (cnt == k) {
                    ans++;
                    // 往右找剩下的偶数
                    while (j < n && (nums[++j] & 1) == 0) ans++;
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    Solution s;
    cout << s.numberOfSubarrays(nums, 3) << endl;
}