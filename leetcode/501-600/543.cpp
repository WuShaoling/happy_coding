#include<iostream>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxL = getMaxDepth(root->left);
        int maxR = getMaxDepth(root->right);
        cout << maxL << " " << maxR << endl;
        int maxD = maxL + maxR - 2;
        maxD = max(maxD, diameterOfBinaryTree(root->left));
        maxD = max(maxD, diameterOfBinaryTree(root->right));
        return maxD;
    }

    int getMaxDepth(TreeNode* root){
        if(!root)
            return 0;
        if(!root->left && !root->right){
            return 1;
        }
        int maxL = getMaxDepth(root->left);
        int maxR = getMaxDepth(root->right);
        return 1 + max(maxL, maxR);
    }
};

int main(){

}