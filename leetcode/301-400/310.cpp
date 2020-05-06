#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n <= 0) return {};
        if (n == 1) return {0};

        vector<int> degree(n, 0);
        vector<vector<int>> graph(n);
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        // 度为1的节点入队
        queue<int> Q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                Q.push(i);
            }
        }

        int rst = n;
        while (rst != 1 && rst != 2) {
            int len = Q.size();
            rst -= len;
            for (int i = 0; i < len; i++) {
                int t = Q.front();
                Q.pop();
                for (int neighbor : graph[t]) {
                    if (degree[neighbor] > 0) degree[neighbor]--;
                    if (degree[neighbor] == 1) Q.push(neighbor);
                }
            }
        }

        vector<int> ans;
        while (!Q.empty()) {
            ans.push_back(Q.front());
            Q.pop();
        }
        return ans;
    }
};

int main() {}