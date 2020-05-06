#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
   public:
    Node* connect(Node* root) {
        if (!root) return root;

        Node* p = root;
        while (p->left) {
            Node* line = p;
            while (line) {
                line->left->next = line->right;
                if (line->next) {
                    line->right->next = line->next->left;
                }
                line = line->next;
            }
            p = p->left;
        }

        return root;
    }
};

int main() {}