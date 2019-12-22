#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        permute(nums, visited, 0);
        return res;
    }

    void permute(vector<int>& nums, vector<bool>& visited, int index) {
        if (index == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

            path.push_back(nums[i]);
            visited[i] = true;
            permute(nums, visited, index + 1);
            visited[i] = false;
            path.pop_back();
        }
    }

   private:
    vector<vector<int>> res;
    vector<int> path;
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 2, 3};
    vector<vector<int>> res = s.permuteUnique(nums);
    for (vector<int> t : res) {
        for (int tt : t) cout << tt << " ";
        cout << endl;
    }
}