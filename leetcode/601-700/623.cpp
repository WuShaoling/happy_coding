#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }
        doAdd(root, v, d, 1);
        return root;
    }

    void doAdd(TreeNode* root, int v, int d, int curD) {
        if (!root) return;

        if (curD + 1 == d) {
            TreeNode* addLeft = new TreeNode(v);
            addLeft->left = root->left;

            TreeNode* addRight = new TreeNode(v);
            addRight->right = root->right;

            root->left = addLeft;
            root->right = addRight;
            return;
        }

        doAdd(root->left, v, d, curD + 1);
        doAdd(root->right, v, d, curD + 1);
    }
};

int main() {}