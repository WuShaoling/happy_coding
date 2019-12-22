#include <algorithm>
#include <iostream>
#include <map>
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

class BSTIterator {
   public:
    stack<TreeNode*> _stack;
    TreeNode* cur;

    BSTIterator(TreeNode* root) { cur = root; }

    /** @return the next smallest number */
    int next() {
        int res = 0;
        while (cur) {
            _stack.push(cur);
            cur = cur->left;
        }
        cur = _stack.top();
        _stack.pop();
        res = cur->val;
        cur = cur->right;
        return res;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() { return cur && !_stack.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {}