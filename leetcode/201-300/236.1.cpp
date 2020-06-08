#include <iostream>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP;
        getPath(root, p, pathP);

        vector<TreeNode*> pathQ;
        getPath(root, q, pathQ);

        for (int i = 1; i < min(pathP.size(), pathQ.size()); i++) {
            if (pathP[i]->val != pathQ[i]->val) return pathP[i - 1];
        }
        return pathP[0];
    }

    bool getPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& path) {
        if (!root) return false;

        if (root->val == p->val) {
            path.push_back(root);
            return true;
        }

        path.push_back(root);
        if (getPath(root->left, p, path)) return true;
        if (getPath(root->right, p, path)) return true;
        path.pop_back();
        return false;
    }
};

int main() {}