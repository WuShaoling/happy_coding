#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;

        // 第一次遍历，构建新的链表
        Node *p = head, *t;
        while (p) {
            t = p->next;
            p->next = new Node(p->val);
            p->next->next = t;
            p = t;
        }

        // 第二次遍历，设置随机节点
        p = head;
        while (p) {
            if (p->random) p->next->random = p->random->next;
            p = p->next->next;
        }

        // 第三次遍历，分开双链表
        p = head;
        Node* newHead = new Node(0);
        Node* newP = newHead;
        while (p) {
            newP->next = p->next;
            p->next = p->next->next;

            newP = newP->next;
            p = p->next;
        }
        newP->next = NULL;

        return newHead->next;
    }
};

// class Solution {
//    public:
//     Node* copyRandomList(Node* head) {
//         if (!head) return head;

//         Node* newHead = new Node(0);
//         Node* newP = newHead;
//         vector<Node*> newPos;  // 保存新的链表节点

//         Node* p = head;
//         int pos = 0;
//         map<Node*, int> nodeToPos;  // 记录节点到位置到映射
//         while (p) {
//             newP->next = new Node(p->val);
//             newPos.push_back(newP->next);
//             nodeToPos[p] = pos;

//             newP = newP->next;
//             p = p->next;
//             pos++;
//         }

//         p = head;
//         newP = newHead->next;
//         while (p) {
//             if (p->random) newP->random = newPos[nodeToPos[p->random]];

//             p = p->next;
//             newP = newP->next;
//         }

//         return newHead->next;
//     }
// };

int main() {
    Solution s;
    Node* p = new Node(0);
    p->next = new Node(1);
    s.copyRandomList(p);
}