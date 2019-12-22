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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2)
            return NULL;

        TreeNode *newTree = new TreeNode(0);
        if(t1 && !t2){
            newTree->val = t1->val;
            newTree->left = mergeTrees(t1->left, NULL);
            newTree->right = mergeTrees(t1->right, NULL);
        }else if(!t1 && t2){
            newTree->val = t2->val;
            newTree->left = mergeTrees(NULL, t2->left);
            newTree->right = mergeTrees(NULL, t2->right);
        }else{
            newTree->val = t1->val + t2->val;
            newTree->left = mergeTrees(t1->left, t2->left);
            newTree->right = mergeTrees(t1->right, t2->right);
        }
        return newTree;
    }
};

int main(){

}