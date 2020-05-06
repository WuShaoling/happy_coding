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
    TreeNode* bstToGst(TreeNode* root) {
        if (root) {
            bstToGst(root->right);

            root->val += sum;
            sum = root->val;

            bstToGst(root->left);
        }
        return root;
    }

   private:
    int sum = 0;
};

int main() {}