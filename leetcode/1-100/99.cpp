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
    void recoverTree(TreeNode* root) {
        find(root);
        swap(x, y);
    }

   private:                      //   x y y
    void find(TreeNode* root) {  // 1 4 3 2 5
        if (!root) return;

        find(root->left);

        if (pre && root->val <= pre->val) {
            if (x == NULL) {
                x = pre;
                y = root;
            } else {
                y = root;
            }
        }
        pre = root;

        find(root->right);
    }

    TreeNode* pre = NULL;
    TreeNode* x = NULL;
    TreeNode* y = NULL;
};

int main() {}