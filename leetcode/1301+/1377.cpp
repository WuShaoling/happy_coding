#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution {
   public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> table(n + 1);
        for (vector<int> v : edges) {
            table[v[0]].push_back(v[1]);
            table[v[1]].push_back(v[0]);
        }

        vector<bool> visited(n + 1, false);
        visited[1] = true;
        dfs(table, visited, t, target, 1.0, res);
        return res;
    }

    bool dfs(vector<vector<int>>& table, vector<bool>& visited, int t,
             int target, int idx, double p) {
        if (t < 0) {  // 时间超了，永远跳不到
            res = 0;
            return false;
        }

        if (target == idx) {
            // 如果跳到了目标点，但是还有时间且还可以往后跳
            if (t != 0) {
                int notVisited = 0;
                for (int i : table[idx]) {
                    if (!visited[i]) notVisited++;
                }
                if (notVisited != 0) {
                    res = 0;
                    return false;
                }
            }
            res = p;
            return true;
        }

        if (!table[idx].empty()) {
            int notVisited = 0;
            for (int i : table[idx]) {
                if (!visited[i]) notVisited++;
            }
            if (notVisited != 0) {
                for (int i : table[idx]) {
                    if (!visited[i]) {
                        visited[i] = true;
                        if (dfs(table, visited, t - 1, target, i,
                                p / (notVisited * 1.0))) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    double res = 1.0;
};

int main() {
    Solution s;
    vector<vector<int>> v = {{1, 2}, {1, 3}, {1, 7}, {2, 4}, {2, 6}, {3, 5}};
    cout << s.frogPosition(7, v, 20, 6);
}