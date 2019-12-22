#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return res;

        sort(candidates.begin(), candidates.end());

        find(candidates, 0, target);
        return res;
    }

   private:
    void find(vector<int>& candidates, int index, int target) {
        if (0 == target) {
            res.push_back(cur);
            return;
        }

        for (int i = index;
             i < candidates.size() && target - candidates[i] >= 0; i++) {
            cur.push_back(candidates[i]);
            find(candidates, target - candidates[i], i);
            cur.pop_back();
        }
    }

    vector<vector<int>> res;
    vector<int> cur;
};

int main() {
    Solution s;
    vector<int> candidates = {4, 2, 7, 5, 6};
    int target = 16;
    vector<vector<int>> res = s.combinationSum(candidates, target);
    for (vector<int> t : res) {
        for (int tt : t) cout << tt << " ";
        cout << endl;
    }
}