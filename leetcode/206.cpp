
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next->next == NULL) return head;
        ListNode* cur = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return cur;
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