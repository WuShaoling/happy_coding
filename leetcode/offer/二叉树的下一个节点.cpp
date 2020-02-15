#include <iostream>
#include <stack>

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
    TreeLinkNode *GetNext(TreeLinkNode *pNode) {}
};

int main() {}