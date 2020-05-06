#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path{0};
        backtrace(graph, graph.size(), 0, path, res);
        return res;
    }

   private:
    void backtrace(const vector<vector<int>>& graph, int n, int i,
                   vector<int>& path, vector<vector<int>>& res) {
        if (i == n - 1) {
            res.push_back(path);
            return;
        }

        for (auto j : graph[i]) {
            path.push_back(j);
            backtrace(graph, n, j, path, res);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> g = {{1, 2}, {3}, {3}, {}};
    vector<vector<int>> ans = s.allPathsSourceTarget(g);
    for (auto it : ans) {
        for (int i : it) cout << i << " ";
        cout << endl;
    }
}