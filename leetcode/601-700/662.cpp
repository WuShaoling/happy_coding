#include <algorithm>
#include <iostream>
#include <queue>
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
    int widthOfBinaryTree(TreeNode *root) {
        if (!root) return 0;

        unsigned long long res = 0;
        deque<pair<TreeNode *, unsigned long long>> q;
        q.push_back({root, 1});
        while (!q.empty()) {
            res = max(res, q.back().second - q.front().second + 1);
            int len = q.size();
            for (int i = 0; i < len; i++) {
                pair<TreeNode *, unsigned long long> top = q.front();
                q.pop_front();
                if (top.first->left)
                    q.push_back({top.first->left, 2 * top.second});
                if (top.first->right)
                    q.push_back({top.first->right, 2 * top.second + 1});
            }
        }

        return res;
    }
};

int main() {}