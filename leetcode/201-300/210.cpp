#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        res.clear();
        if (!topologySort(numCourses, prerequisites)) return {};
        return res;
    }

    bool topologySort(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> indegree(numCourses);

        // 求入度和依赖表
        for (vector<int> v : prerequisites) {
            g[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }

        // 入度为0的节点入队
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int top = q.front();
            q.pop();
            res.push_back(top);
            numCourses--;
            for (int i : g[top]) {
                if (--indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        return numCourses == 0;
    }

    vector<int> res;
};

int main() {}