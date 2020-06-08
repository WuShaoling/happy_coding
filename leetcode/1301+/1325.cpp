#include <algorithm>
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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (doRemove(root, target)) return NULL;
        return root;
    }

    bool doRemove(TreeNode* root, int target) {
        if (!root) return false;

        if (!root->left && !root->right) {
            if (root->val == target) return true;
        }

        // 当前不是叶子节点
        if (doRemove(root->left, target)) root->left = NULL;
        if (doRemove(root->left, target)) root->right = NULL;

        return root->val == target && !root->left && !root->right;
    }
};

int main() {}