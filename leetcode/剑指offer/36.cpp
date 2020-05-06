#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Node {
   public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
   public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        Node* p = root;
        inorder(p);

        Node* tail = root;
        while (tail->right) tail = tail->right;

        Node* head = root;
        while (head->left) head = head->left;

        head->left = tail;
        tail->right = head;

        return head;
    }

   private:
    Node* pre = NULL;
    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);

        if (pre) {
            root->left = pre;
            pre->right = root;
        }
        pre = root;

        inorder(root->right);
    }
};

int main() {}