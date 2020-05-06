#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
   public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode) {
        if (!pNode) return NULL;

        // 如果有右子树，一直查找右子树的左子树
        if (pNode->right) {
            TreeLinkNode *p = pNode->right;
            while (p->left) {
                p = p->left;
            }
            return p;
        }
        // 如果当前节点是上个节点的左子树
        if (pNode->next && pNode->next->left == pNode) {
            return pNode->next;
        }
        // 如果当前节点是上个节点的右子树
        if (pNode->next) {
            TreeLinkNode *p = pNode->next;
            while (p->next && p->next->right == p) {
                p = p->next;
            }
            return p->next;
        }
        return NULL;
    }
};

int main() {}