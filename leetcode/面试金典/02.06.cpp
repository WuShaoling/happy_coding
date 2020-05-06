#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    bool isPalindrome(ListNode* head) {
        ListNode* H = new ListNode(0);
        H->next = head;

        ListNode* fast = H;
        ListNode* slow = H;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        reverse(slow);

        ListNode* p = head;
        slow = slow->next;
        while (p && slow) {
            if (slow->val != p->val) return false;
        }

        return true;
    }

    void reverse(ListNode* head) {
        ListNode* p = head->next;
        head->next = NULL;
        while (p) {
            ListNode* t = p->next;
            p->next = head->next;
            head->next = p;
            p = t;
        }
    }
};

int main() {
    // ListNode* head = new ListNode(0);
    // ListNode* p = head;
    // for (int i = 1; i <= 10; i++) {
    //     p->next = new ListNode(i);
    //     p = p->next;
    // }

    // p = head;
    // while (p) {
    //     cout << p->val << " ";
    //     p = p->next;
    // }
    // cout << endl;

    // Solution s;
    // head = s.reverse(head);

    // p = head;
    // while (p) {
    //     cout << p->val << " ";
    //     p = p->next;
    // }
    // cout << endl;
}