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
    int sumEvenGrandparent(TreeNode* root) {
        helper(root);
        return res;
    }

   private:
    void helper(TreeNode* root) {
        if (!root) return;
        if (root->val % 2 == 0) {
            if (root->left) {
                TreeNode* lChild = root->left;
                if (lChild->left) res += lChild->left->val;
                if (lChild->right) res += lChild->right->val;
            }
            if (root->right) {
                TreeNode* rChild = root->right;
                if (rChild->left) res += rChild->left->val;
                if (rChild->right) res += rChild->right->val;
            }
        }

        helper(root->left);
        helper(root->right);
    }

    int res = 0;
};

int main() {}