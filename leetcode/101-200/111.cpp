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
    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        return (left && right) ? 1 + min(left, right) : 1 + left + right;

        // if(root->left == NULL && root->right != NULL){
        //     return 1+minDepth(root->right);
        // }
        // if(root->left != NULL && root->right == NULL){
        //     return 1+minDepth(root->left);
        // }
        // return 1+min(minDepth(root->left), minDepth(root->right));
    }
};

int main() {}