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
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return getAns(1, n);
    }

    vector<TreeNode *> getAns(int start, int end) {
        vector<TreeNode *> ans;
        // 此时没有数字，将 null 加入结果中
        if (start > end) {
            ans.push_back(NULL);
            return ans;
        }
        // 只有一个数字，当前数字作为一棵树加入结果中
        if (start == end) {
            ans.push_back(new TreeNode(start));
            return ans;
        }
        //尝试每个数字作为根节点
        for (int i = start; i <= end; i++) {
            //得到所有可能的左子树
            vector<TreeNode *> leftTrees = getAns(start, i - 1);
            //得到所有可能的右子树
            vector<TreeNode *> rightTrees = getAns(i + 1, end);
            //左子树右子树两两组合
            for (TreeNode *leftTree : leftTrees) {
                for (TreeNode *rightTree : rightTrees) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    //加入到最终结果中
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};

int main() {}