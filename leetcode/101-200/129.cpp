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
    int sumNumbers(TreeNode *root) {
        search(root, 0);
        return res;
    }

   private:
    void search(TreeNode *root, int sum) {
        if (!root) return;

        if (!root->left && !root->right) {
            res += sum * 10 + root->val;
            return;
        }

        sum = sum * 10 + root->val;
        if (root->left) search(root->left, sum);
        if (root->right) search(root->right, sum);
    }

    int res;
};

int main() {}