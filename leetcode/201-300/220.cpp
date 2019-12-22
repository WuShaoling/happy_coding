#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
   public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<double> s;
        set<double>::iterator it;
        for (int i = 0; i < nums.size(); i++) {
            for (it = s.begin(); it != s.end(); it++) {
                double diff = fabs((double)nums[i] - (double)*it);
                if (diff <= t) {
                    return true;
                }
                s.insert(nums[i]);
                if (s.size() > k) {
                    s.erase(nums[i - k]);
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2147483647, -2147483647};
    cout << s.containsNearbyAlmostDuplicate(nums, 1, 2147483647);
}