#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(nums, 0);
        return res;
    }

    void helper(vector<int>& nums, int k) {
        if (k == nums.size()) return;

        for (int i = k; i < nums.size(); i++) {
            path.push_back(nums[i]);
            res.push_back(path);
            helper(nums, i + 1);
            path.pop_back();
        }
    }

    vector<int> path;
    vector<vector<int>> res = {{}};
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = s.subsets(nums);
    for (auto it : res) {
        for (int i : it) cout << i;
        cout << endl;
    }
}