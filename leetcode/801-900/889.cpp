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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int len = pre.size();
        for (int i = 0; i < post.size(); i++) mm[post[i]] = i;
        return build(pre, post, 0, len - 1, 0, len - 1);
    }

    TreeNode* build(vector<int>& pre, vector<int>& post, int preStart,
                    int preEnd, int postStart, int postEnd) {
        if (preStart > preEnd) return NULL;
        if (preStart == preEnd) return new TreeNode(pre[preStart]);

        TreeNode* root = new TreeNode(pre[preStart]);
        //         0 1 2 3 4 5 6
        // pre  = [1,2,4,5,3,6,7]
        // post =   [4,5,2,6,7,3,1]
        //           0 1 2 3 4 5 6

        int val = pre[preStart + 1];
        if (mm.find(val) != mm.end()) {
            int i = mm[val];
            int len = i - postStart;
            root->left = build(pre, post, preStart + 1, preStart + 1 + len,
                               postStart, i);
            root->right = build(pre, post, preStart + len + 2, preEnd, i + 1,
                                postEnd - 1);
            return root;
        }
        return NULL;
    }

    map<int, int> mm;
};

int main() {}