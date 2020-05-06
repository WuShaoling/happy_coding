#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* temp = slow->next;
        slow->next = NULL;
        head = sortList(head);
        temp = sortList(temp);
        return merge(head, temp);
    }

    ListNode* merge(ListNode* h1, ListNode* h2) {
        ListNode* merge = new ListNode(0);
        ListNode* p = merge;

        while (h1 && h2) {
            if (h1->val < h2->val) {
                p->next = h1;
                h1 = h1->next;
            } else {
                p->next = h2;
                h2 = h2->next;
            }
            p = p->next;
        }
        if (h1) p->next = h1;
        if (h2) p->next = h2;

        return merge->next;
    }
};

// class Solution {
//    public:
//     ListNode* sortList(ListNode* head) {
//         if (!head) return NULL;
//         return mergeSort(head, NULL);
//     }

//     ListNode* mergeSort(ListNode* head, ListNode* tail) {
//         if (head == tail || head->next == tail) return head;  // [)

//         ListNode* fast = head;
//         ListNode* slow = head;
//         while (fast != tail && fast->next != tail) {
//             fast = fast->next->next;
//             slow = slow->next;
//         }

//         mergeSort(head, slow);  // [head, slow)
//         mergeSort(slow, tail);  // [slo, tail)
//         return merge(head, slow, tail);
//     }

//     ListNode* merge(ListNode* head, ListNode* mid, ListNode* tail) {
//         ListNode* newHead = new ListNode(0);
//         ListNode* p = newHead;
//         ListNode* p1 = head;
//         ListNode* p2 = mid;

//         while (p1 != mid && p2 != tail) {
//             if (p1->val < p2->val) {
//                 p->next = p1;
//                 p = p->next;
//                 p1 = p1->next;
//             } else {
//                 p->next = p2;
//                 p = p->next;
//                 p2 = p2->next;
//             }
//         }
//         while (p1 != mid && p1) {
//             p->next = p1;
//             p = p->next;
//             p1 = p1->next;
//         }
//         while (p2 != tail && p2) {
//             p->next = p2;
//             p = p->next;
//             p2 = p2->next;
//         }
//         p->next = NULL;
//         return newHead->next;
//     }
// };

int main() {}