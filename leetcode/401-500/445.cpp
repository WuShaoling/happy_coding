#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        stack<int> st1;
        while (p) {
            st1.push(p->val);
            p = p->next;
        }

        p = l2;
        stack<int> st2;
        while (p) {
            st2.push(p->val);
            p = p->next;
        }

        int flag = 0;
        int sum = 0;
        ListNode* ans = new ListNode(-1);
        while (!st1.empty() && !st2.empty()) {
            sum = st1.top() + st2.top() + flag;
            st1.pop();
            st2.pop();
            flag = sum / 10;

            p = new ListNode(sum % 10);
            p->next = ans->next;
            ans->next = p;
        }
        while (!st1.empty()) {
            sum = st1.top() + flag;
            st1.pop();
            flag = sum / 10;

            p = new ListNode(sum % 10);
            p->next = ans->next;
            ans->next = p;
        }
        while (!st2.empty()) {
            sum = st2.top() + flag;
            st2.pop();
            flag = sum / 10;

            p = new ListNode(sum % 10);
            p->next = ans->next;
            ans->next = p;
        }
        if (flag == 1) {
            p = new ListNode(sum % 10);
            p->next = ans->next;
            ans->next = p;
        }

        return ans->next;
    }
};

/*
7243
 564
7807
*/

int main() {}