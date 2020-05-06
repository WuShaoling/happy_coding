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
    int findSecondMinimumValue(TreeNode* root) { return find(root, root->val); }

    int find(TreeNode* root, int val) {
        if (!root) return -1;
        if (root->val > val) return root->val;

        int left = find(root->left, val);
        int right = find(root->right, val);
        if (left == -1) return right;
        if (right == -1) return left;

        return min(left, right);
    }
};

int main() {}