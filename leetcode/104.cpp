#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    int maxDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left != NULL && root->right == NULL) {
            return 1 + maxDepth(root->left);
        }
        if (root->left == NULL && root->right != NULL) {
            return 1 + maxDepth(root->right);
        }

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return l > r ? 1 + l : 1 + r;
    }
};

int main() {}