#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = head;
        int count = k;
        while (p && count) {
            count--;
            p = p->next;
        }
        if (count > 0) return head;

        ListNode* pre = NULL;
        p = head, count = k;
        while (count--) {
            ListNode* temp = p->next;
            p->next = pre;
            pre = p;
            p = temp;
        }

        head->next = reverseKGroup(p, k);
        return pre;
    }
};

int main() {}