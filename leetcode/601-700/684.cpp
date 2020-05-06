#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int find(vector<int>& f, int i) {
        if (i != f[i]) f[i] = find(f, f[i]);
        return f[i];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> f(n + 1);

        for (int i = 0; i <= n; i++) f[i] = i;

        vector<int> res;
        for (int i = 0; i < n; i++) {
            int x_f = find(f, edges[i][0]);
            int y_f = find(f, edges[i][1]);
            if (x_f == y_f) {
                res = edges[i];
            } else {
                f[y_f] = x_f;
            }
        }

        return res;
    }
};

int main() {}