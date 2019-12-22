#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    string smallestFromLeaf(TreeNode *root) {
        dfs(root, "");
        reverse(res.begin(), res.end());
        return res;
    }

   private:
    void dfs(TreeNode *root, string cur) {
        if (!root) return;

        if (!root->left && !root->right) {
            if (res == "") {
                res = cur;
            } else {
                if (cur.size() == res.size() && cur < res) {
                    res = cur;
                } else if (cur.size() < res.size()) {
                    res = cur;
                }
            }
        }

        cur = (char)('a' + root->val) + cur;

        dfs(root->left, cur);
        dfs(root->right, cur);
    }
    string res = "";
};

int main() {}