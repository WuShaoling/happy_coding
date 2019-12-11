#include <iostream>
#include <sstream>
#include <stack>
#include <string>
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
    bool isValidBST(TreeNode* root) { return check(root, false, 0, false, 0); }

    bool check(TreeNode* root, bool low, int lowBound, bool high,
               int highBound) {
        if (!root) return true;

        if (low && root->val <= lowBound) {
            cout << "l " << root->val << " " << lowBound << endl;
            return false;
        }
        if (high && root->val >= highBound) {
            cout << "r " << root->val << " " << highBound << endl;
            return false;
        }

        if (!check(root->left, low, lowBound, true, root->val)) return false;
        if (!check(root->right, true, root->val, high, highBound)) return false;

        return true;
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution s;
    cout << s.isValidBST(root);
}