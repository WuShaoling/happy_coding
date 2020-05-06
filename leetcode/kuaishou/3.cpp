#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * 根据顾客属性计算出顾客排队顺序
     * @param a int整型vector 顾客a属性
     * @param b int整型vector 顾客b属性
     * @return int整型vector
     */
    vector<int> WaitInLine(vector<int>& a, vector<int>& b) {
        vector<vector<int>> nodes(a.size(), vector<int>(2, 0));
        for (int i = 0; i < a.size(); i++) {
            nodes[i][0] = i + 1;
            nodes[i][1] = a[i] - b[i];
        }
        sort(nodes.begin(), nodes.end(),
             [](const vector<vector<int>>& a, const vector<vector<int>>& b) {
                 return a[1] >= b[1];
             });
        vector<int> ans;
        for (vector<int> node : nodes) {
            ans.push_back(node[1]);
        }
        return ans;
    }
};

int main() {}