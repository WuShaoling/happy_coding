#include <iostream>
#include <sstream>
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
    // ListNode* reverseList(ListNode* head) {
    //     if (head == NULL || head->next->next == NULL) return head;
    //     ListNode* cur = reverseList(head->next);
    //     head->next->next = head;
    //     head->next = NULL;
    //     return cur;
    // }

    ListNode* reverseList(ListNode* head) {
        if (!head) return head;

        vector<ListNode*> v;
        while (head) {
            v.push_back(head);
            head = head->next;
        }

        head = new ListNode(0);
        ListNode* p = head;
        for (int i = v.size() - 1; i >= 0; i--) {
            p->next = v[i];
            p = p->next;
        }
        p->next = NULL;

        return head->next;
    }
};

int main() {
    ListNode* root = new ListNode(0);
    ListNode* p = root;
    for (int i = 1; i <= 10; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    Solution s;
    ListNode* res = s.reverseList(root);
    p = res;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
}