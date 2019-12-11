#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<string> binaryTreePaths(TreeNode *root) {
        search(root, "");
        return res;
    }

   private:
    void search(TreeNode *root, string path) {
        if (!root) return;

        if (!root->left && !root->right) {
            path += to_string(root->val);
            res.push_back(path);
            return;
        }

        path += to_string(root->val) + "->";
        if (root->left) search(root->left, path);
        if (root->right) search(root->right, path);
    }
    vector<string> res;
};

int main() {}