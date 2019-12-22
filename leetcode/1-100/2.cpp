#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* res = new ListNode(0);
        ListNode* p = res;

        int n = 0;
        while (p1 && p2) {
            int t = p1->val + p2->val + n;
            p->val = t % 10;
            n = t / 10;
            if (p1->next || p2->next || n) {
                p->next = new ListNode(0);
            }
            p = p->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1) {
            int t = p1->val + n;
            p->val = t % 10;
            n = t / 10;
            if (p1->next || n != 0) {
                p->next = new ListNode(0);
            }
            p = p->next;
            p1 = p1->next;
        }
        while (p2) {
            int t = p2->val + n;
            p->val = t % 10;
            n = t / 10;
            if (p2->next || n != 0) {
                p->next = new ListNode(0);
            }
            p = p->next;
            p2 = p2->next;
        }
        if (n != 0) {
            p->val = n;
        }
        return res;
    }
};

int main() {}