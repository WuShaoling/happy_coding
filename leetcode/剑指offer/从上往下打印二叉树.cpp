#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        vector<int> res;
        if (!root) return res;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *t = q.front();
            q.pop();
            res.push_back(t->val);
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }

        return res;
    }
};

int main() {}