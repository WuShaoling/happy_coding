#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>> mm;
        vector<int> dis(n, INT_MAX);  // 距离
        vector<int> vis(n, 0);        // 访问标记
        queue<int> q;

        for (int i = 0; i < n - 1; i++) {
            mm[arr[i]].push_back(i);
        }

        dis[n - 1] = 0;
        q.push(n - 1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
        }
    }
};

int main() {}