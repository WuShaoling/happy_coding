#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        helper(1, k, n);
        return res;
    }

   private:
    void helper(int index, int k, int n) {
        if (path.size() == k) {
            if (n == 0) res.push_back(path);
            return;
        }

        for (int i = index; i <= 9; i++) {
            if (i > n) return;
            path.push_back(i);
            helper(i + 1, k, n - i);
            path.pop_back();
        }
    }

    vector<int> path;
    vector<vector<int>> res;
};

int main() {
    Solution s;
    vector<vector<int>> res = s.combinationSum3(3, 9);
    for (vector<int> v : res) {
        for (int i : v) cout << i << " ";
        cout << endl;
    }
}