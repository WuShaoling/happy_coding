#include <iostream>
#include <map>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mm;
        int i = 0;
        for (int v : inorder) mm[v] = i++;

        post_root_index = postorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size(), mm);
    }

   private:
    int post_root_index;
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int in_left,
                    int in_right, map<int, int>& mm) {
        if (in_left >= in_right) return NULL;

        int root_val = postorder[post_root_index];
        post_root_index--;
        int in_root_index = mm[root_val];

        TreeNode* root = new TreeNode(root_val);
        root->right =
            build(inorder, postorder, in_root_index + 1, in_right, mm);
        root->left = build(inorder, postorder, in_left, in_root_index, mm);

        return root;
    }
};

int main() {}