#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* newHead = new ListNode(-1);
        newHead->next = head;

        // 取中点
        ListNode* fast = newHead;
        ListNode* slow = newHead;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // 分割链表
        ListNode* part2 = slow->next;
        slow->next = NULL;
        part2 = reverseList(part2);

        ListNode* p1 = head;
        ListNode* p2 = part2;
        ListNode* p = newHead;
        while (p1 && p2) {
            p->next = p1;
            p1 = p1->next;
            p = p->next;

            p->next = p2;
            p2 = p2->next;
            p = p->next;
        }
        if (p1) {
            p->next = p1;
            p = p->next;
        } else if (p2) {
            p->next = p2;
            p = p->next;
        }
        p->next = NULL;
        head = newHead->next;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* p = head;
        while (p) {
            ListNode* t = p->next;
            p->next = pre;
            pre = pre->next;
            p = t;
        }
        return pre;
    }
};
/*
            f
0 1 2 3 4 5
      s

1 2
3 4

    l
1 2 3
pre
  1 2 3
  p
        f
    1 5 2 4 3

*/

int main() {}