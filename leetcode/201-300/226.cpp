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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        if(root->left){
            invertTree(root->left);
        }
        if(root->right){
            invertTree(root->right);
        }
        TreeNode* t = root->left;
        root->left = root->right;
        root->right = t;
        return root;
    }
};

int main(){

}