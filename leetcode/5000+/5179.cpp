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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> values;
        inorder(root, values);
        return build(values, 0, values.size());
    }

   private:
    TreeNode* build(vector<int>& values, int left, int right) {
        if (left > right) return NULL;
        int mid = left + ((right - left) >> 1);
        TreeNode* root = new TreeNode(values[mid]);
        root->left = build(values, left, mid - 1);
        root->right = build(values, mid + 1, right);
        return root;
    }

    void inorder(TreeNode* root, vector<int>& values) {
        if (!root) return;
        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
    }
};

int main() {}