#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1 || !pHead2) return NULL;

        int count1 = getLength(pHead1);
        int count2 = getLength(pHead2);

        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        if (count1 > count2) {
            for (int i = 0; i < count1 - count2; i++) p1 = p1->next;
        } else if (count1 < count2) {
            for (int i = 0; i < count2 - count1; i++) p2 = p2->next;
        }

        while (p1) {
            if (p1 == p2) return p1;
            p1 = p1->next;
            p2 = p2->next;
        }

        return NULL;
    }

   private:
    int getLength(ListNode* pHead) {
        ListNode* p = pHead;
        int res = 0;
        while (p) {
            res++;
            p = p->next;
        }
        return res;
    }
};