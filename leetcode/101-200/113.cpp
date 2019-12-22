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
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<int> path;
        search(root, path, sum);
        return res;
    }

    void search(TreeNode *root, vector<int> path, int sum) {
        if (!root) return;

        // leaf node
        if (!root->left && !root->right) {
            if (root->val == sum) res.push_back(path);
            return;
        }

        path.push_back(root->val);
        if (root->left) search(root->left, path, sum - root->val);
        if (root->right) search(root->left, path, sum - root->val);
    }

    vector<vector<int>> res;
};

int main() {}