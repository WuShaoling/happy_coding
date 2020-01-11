#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return res;
        helper(root, 0, 0);

        for (auto& itX : mm) {
            for (auto itY : itX.second) {
                if (itY.second.size() != 0) {
                    sort(itY.second.begin(), itY.second.end());
                    res.push_back(itY.second);
                }
            }
        }

        // for (int i = 0; i < 2010; i++) {  // x
        //     vector<int> t;
        //     for (int j = 0; j < 1010; j++) {  // y

        //         if (path[i][j].size() != 0) {
        //             sort(path[i][j].begin(), path[i][j].end());
        //             for (int k : path[i][j]) t.push_back(k);
        //         }
        //     }
        //     if (t.size() != 0) res.push_back(t);
        // }
        return res;
    }

   private:
    void helper(TreeNode* root, int x, int y) {
        if (!root) return;
        mm[x][y].push_back(root->val);
        // path[1005 + x][y].push_back(root->val);
        helper(root->left, x - 1, y + 1);
        helper(root->right, x + 1, y + 1);
    }

    vector<vector<int>> res;
    map<int, map<int, vector<int>>> mm;
    // vector<int> path[2010][1010];
};

int main() {}