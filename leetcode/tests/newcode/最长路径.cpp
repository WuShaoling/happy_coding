#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    long long solve(int n, vector<int>& u, vector<int>& v, vector<int>& w) {
        vector<vector<pair<int, int>>> g(n + 1);
        for (int i = 0; i < u.size(); i++) {
            g[u[i]].push_back({v[i], w[i]});
        }
    }

    long long find(int root, vector<vector<pair<int, int>>>& g) {
        
    }
};

int main() {}