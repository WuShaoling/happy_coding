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
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }

   private:
    int ans = 0;
    vector<int> dfs(TreeNode* root) {
        if (!root) return {1, INT_MAX, INT_MIN, 0};

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        // 其中一个子数不是BST
        if (!left[0] || !right[0]) return {0, 0, 0, 0};
        // 如果小于等于左子树的最大值
        if (root->val <= left[2]) return {0, 0, 0, 0};
        // 如果大于等于左子树的最大值
        if (root->val >= right[1]) return {0, 0, 0, 0};

        int curMax = root->right ? right[2] : root->val;
        int curMin = root->left ? left[1] : root->val;

        int sum = right[3] + left[3] + root->val;
        ans = max(ans, sum);
        return {true, curMin, curMax, sum};
    }
};

int main() {}