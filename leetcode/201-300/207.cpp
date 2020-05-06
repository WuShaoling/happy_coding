#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // return topologySort(numCourses, prerequisites);
        vector<vector<int>> g(numCourses);
        vector<int> status(numCourses);

        for (vector<int> v : prerequisites) {
            g[v[1]].push_back(v[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(status, g, i)) return false;
        }

        return true;
    }

    bool dfs(vector<int>& status, vector<vector<int>>& g, int index) {
        if (status[index] == 1) return false;
        if (status[index] == -1) return true;

        status[index] = 1;
        for (int i : g[index]) {
            if (!dfs(status, g, i)) return false;
        }
        status[index] = -1;
        return true;
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
            numCourses--;
            for (int i : g[top]) {
                if (--indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        return numCourses == 0;
    }
};

int main() {}