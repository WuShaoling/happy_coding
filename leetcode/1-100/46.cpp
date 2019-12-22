#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        doPermute(nums, visited, 0);
        return res;
    }

   private:
    void doPermute(vector<int>& nums, vector<bool>& visited, int index) {
        if (index == nums.size()) {
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;

            cur.push_back(nums[i]);
            visited[i] = true;

            doPermute(nums, visited, index + 1);

            visited[i] = false;
            cur.pop_back();
        }
    }

    vector<vector<int>> res;
    vector<int> cur;
};

// class Solution {
//    public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         search(nums, 0);
//         return res;
//     }

//    private:
//     void search(vector<int>& nums, int index) {
//         if (index == nums.size()) {
//             res.push_back(nums);
//             return;
//         }

//         for (int i = index; i < nums.size(); i++) {
//             swap(nums[index], nums[i]);
//             search(nums, index + 1);
//             swap(nums[index], nums[i]);
//         }
//     }

//     vector<vector<int>> res;
// };

int main() {
    Solution s;
    vector<int> candidates = {1, 2, 3};
    vector<vector<int>> res = s.permute(candidates);
    for (vector<int> t : res) {
        for (int tt : t) cout << tt << " ";
        cout << endl;
    }
}