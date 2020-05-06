#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> visited(nums.size(), false);
        vector<int> path;
        vector<vector<int>> ans;
        backtrack(nums, visited, path, ans, 0);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<int>& visited, vector<int>& path,
                   vector<vector<int>>& ans, int index) {
        ans.push_back(path);

        for (int i = index; i < nums.size(); i++) {
            if (visited[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

            path.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums, visited, path, ans, i + 1);
            visited[i] = false;
            path.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = s.subsetsWithDup(nums);
    for (auto it : ans) {
        for (int num : it) {
            cout << num << " ";
        }
        cout << endl;
    }
}