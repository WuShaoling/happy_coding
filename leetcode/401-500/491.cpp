#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        DFS(nums, 0, -101);
        vector<vector<int>> res;
        for (vector<int> v : paths) res.push_back(v);
        return res;
    }

    void DFS(vector<int> nums, int index, int pre_num) {
        if (path.size() >= 2) {
            paths.insert(path);
        }

        for (int i = index; i < nums.size(); ++i) {
            if (nums[i] < pre_num) continue;
            path.push_back(nums[i]);
            DFS(nums, i + 1, nums[i]);
            path.pop_back();
        }
    }

    set<vector<int>> paths;
    vector<int> path;
};

int main() {
    vector<int> nums = {4, 6, 7, 7};
    Solution s;
    vector<vector<int>> res = s.findSubsequences(nums);
    for (vector<int> v : res) {
        for (int vv : v) cout << vv << " ";
        cout << endl;
    }
}