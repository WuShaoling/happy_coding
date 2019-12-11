#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* head = new ListNode(0);
        ListNode* p = head;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                p->next = l1->next;
                l1 = l1->next;
            } else {
                p->next = l2->next;
                l2 = l2->next;
            }
            p = p->next;
        }

        if (l1) p->next = l1;
        if (l2) p->next = l2;

        return head;
    }
};

int main() {}