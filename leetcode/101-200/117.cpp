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
        Node* curRoot = root;
        while (true) {
            if (!curRoot) return root;

            while (curRoot) {
            }
            // 从左向右找到第一个非空节点
            while (true) {
            }
        }
    }
};

int main() {}