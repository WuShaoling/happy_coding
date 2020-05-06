#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start,
                               int target) {
        vector<vector<int>> g(n);
        for (vector<int> v : graph) {
            g[v[0]].push_back(v[1]);
        }

        vector<bool> visit(n, false);
        queue<int> q;
        q.push(start);
        visit[start] = true;
        while (!q.empty()) {
            int t = q.front();
            q.pop();

            if (t == target) return true;

            visit[t] = true;
            for (int next : g[t]) {
                if (!visit[next]) {
                    q.push(next);
                }
            }
        }

        return false;
    }
};

int main() {}