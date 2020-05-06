#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i : nums) {
            sum += i;
            if (mp.find(sum - k) != mp.end()) ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1};
    cout << s.subarraySum(nums, 2) << endl;
}