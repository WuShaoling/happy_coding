#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot1 || !pRoot2) return false;

        stack<TreeNode*> s;
        while (!s.empty() || !pRoot1) {
            while (pRoot1) {
                s.push(pRoot1);
                pRoot1 = pRoot1->left;
            }
            pRoot1 = s.top();
            s.pop();

            if (sameAs(pRoot1, pRoot2)) return true;

            pRoot1 = pRoot1->right;
        }

        return false;
    }

    bool sameAs(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;

        if (root1->val != root2->val) return false;

        return sameAs(root1->left, root2->left) &&
               sameAs(root1->right, root2->right);
    }
};

int main() {}