#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        search(candidates, target, 0);

        vector<vector<int>> uniqueRes;
        for (set<vector<int>>::iterator it = res.begin(); it != res.end();
             it++) {
            uniqueRes.push_back(*it);
        }
        return uniqueRes;
    }

   private:
    void search(vector<int>& candidates, int target, int index) {
        if (target == 0) {
            res.insert(path);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (target < candidates[i]) return;
            path.push_back(candidates[i]);
            search(candidates, target - candidates[i], i + 1);
            path.pop_back();
        }
    }

    set<vector<int>> res;
    vector<int> path;
};

int main() {
    Solution s;
    vector<int> candidates = {2, 5, 2, 1, 2};
    vector<vector<int>> res = s.combinationSum2(candidates, 5);
    for (vector<int> t : res) {
        for (int tt : t) cout << tt << " ";
        cout << endl;
    }
}