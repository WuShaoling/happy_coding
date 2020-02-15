#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* newHead = new ListNode(0);

        ListNode* p = pHead;
        while (p) {
            ListNode* t = p->next;

            p->next = newHead->next;
            newHead->next = p;

            p = t;
        }

        return newHead->next;
    }
};

int main() {
    Solution s;
    ListNode* h = new ListNode(0);
    ListNode* p = h;
    for (int i = 1; i <= 10; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    ListNode* res = s.ReverseList(h);
    p = res;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
}