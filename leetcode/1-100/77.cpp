#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        if (n <= 0) return res;
        if (k <= 0) return res;

        helper(n, k, 1);
        return res;
    }

   private:
    void helper(int n, int k, int index) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        for (int i = index; i <= n; i++) {
            path.push_back(i);
            helper(n, k, i + 1);
            path.pop_back();
        }
    }

    vector<int> path;
    vector<vector<int>> res;
};

int main() {
    Solution s;
    vector<vector<int>> res = s.combine(4, 2);
    for (vector<int> v : res) {
        for (int i : v) cout << i << " ";
        cout << endl;
    }
}