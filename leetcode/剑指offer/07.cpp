#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mm[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, inorder.size() - 1);
    }

   private:
    int preorder_root_index = 0;
    map<int, int> mm;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int inorder_left, int inorder_right) {
        if (inorder_left > inorder_right) return NULL;

        // cout << inorder_left << " " << inorder_right << endl;

        int preorder_root = preorder[preorder_root_index];
        preorder_root_index++;
        int inorder_root_index = mm[preorder_root];

        TreeNode* root = new TreeNode(preorder_root);
        root->left =
            build(preorder, inorder, inorder_left, inorder_root_index - 1);
        root->right =
            build(preorder, inorder, inorder_root_index + 1, inorder_right);
        return root;
    }
};

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution s;
    s.buildTree(preorder, inorder);
}