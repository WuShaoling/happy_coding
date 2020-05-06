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
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = new ListNode(0);

        ListNode* p = head;
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
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    for (int i = 1; i <= 10; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    head = p = s.reverseList(head);
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
}