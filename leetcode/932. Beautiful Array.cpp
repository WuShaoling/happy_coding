#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> dfs(int N) {
        if (N == 1) return {1};
        vector<int> left = dfs((N + 1) / 2);
        vector<int> right = dfs(N / 2);
        vector<int> sum;
        for (int x: left)
            sum.push_back(x * 2 - 1);
        for (int x: right)
            sum.push_back(x * 2);
        return sum;
    }

    vector<int> beautifulArray(int N) {
        return dfs(N);
    }
};

int main() {
    Solution solution;

    vector<int> res = solution.beautifulArray(7);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}
