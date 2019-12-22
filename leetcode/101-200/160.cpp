#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode *pA = headA;
        ListNode *pB = headB;
        while (pA && pB) {
            lenA++;
            lenB++;
            pA = pA->next;
            pB = pB->next;
        }
        while (pA) {
            lenA++;
            pA = pA->next;
        }
        while (pB) {
            lenB++;
            pB = pB->next;
        }

        int diff = abs(lenA - lenB);
        ListNode *pt = headA;
        if (lenA < lenB) {
            pt = headB;
        }
        while (diff-- && pt) {
            pt = pt->next;
        }

        if (lenA < lenB) {
            pA = headA;
            pB = pt;
        } else {
            pA = pt;
            pB = headB;
        }
        while (pA && pB) {
            if (pA == pB) {
                return pA;
            }
            pA = pA->next;
            pB = pB->next;
        }
        return NULL;
    }
};