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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        ListNode* head = new ListNode(0);
        ListNode* sum = head;

        int flag = 0;
        while (p1 && p2) {
            int v = p1->val + p2->val + flag;
            sum->next = new ListNode(v % 10);
            flag = v / 10;
            p1 = p1->next;
            p2 = p2->next;
            sum = sum->next;
        }
        while (p1) {
            int v = p1->val + flag;
            sum->next = new ListNode(v % 10);
            flag = v / 10;
            p1 = p1->next;
            sum = sum->next;
        }
        while (p2) {
            int v = p2->val + flag;
            sum->next = new ListNode(v % 10);
            flag = v / 10;
            p2 = p2->next;
            sum = sum->next;
        }

        if (flag) sum->next = new ListNode(flag);

        return head->next;
    }
};

// 7 1 6
// 5 9 2
// 2 1 9

int main() {}
