#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    vector<int> printListFromTailToHead(ListNode *head) {
        vector<int> res;
        printList(head, res);
        return res;
    }

    void printList(ListNode *head, vector<int> &res) {
        if (head == NULL) return;
        printList(head->next, res);
        res.push_back(head->val);
    }
};

int main() {
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    for (int i = 1; i <= 10; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    Solution s;
    vector<int> res = s.printListFromTailToHead(head);
    for (int v : res) cout << v << " ";
}