#include <iostream>
#include <queue>
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        helper(root1);
        helper(root2);
        while (!que.empty()) {
            res.push_back(que.top());
            que.pop();
        }
        return res;
    }

    void helper(TreeNode* root) {
        if (!root) return;
        que.push(root->val);
        helper(root->left);
        helper(root->right);
    }

    priority_queue<int, vector<int>, less<int>> que;
};

int main() {}