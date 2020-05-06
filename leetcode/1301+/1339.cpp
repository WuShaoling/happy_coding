#include <algorithm>
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
    int maxProduct(TreeNode* root) {
        sum = sumTree(root);
        helper(root);
        return (int)(res % (long long)(1e9 + 7));
    }

   private:
    long long helper(TreeNode* root) {
        if (!root) return 0;
        long long left = helper(root->left);
        long long right = helper(root->right);
        long long cur = left + right + root->val;
        res = max(res, (sum - cur) * cur);
        return cur;
    }

    long long sumTree(TreeNode* root) {
        if (!root) return 0;
        return root->val + sumTree(root->left) + sumTree(root->right);
    }

    long long sum = 0;
    long long res = 0;
};

int main() {}