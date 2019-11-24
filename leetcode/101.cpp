#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* t1, TreeNode* t2){
        if(!t1 && !t2){
            return true;
        }
        if(!t1 || !t2){
            return false;
        }
        if(t1->val == t2->val) {
            return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
        }
        return false;
    }
};

int main(){

}