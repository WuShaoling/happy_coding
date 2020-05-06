#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp {
    bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (ListNode* head : lists) pq.push(head);
        ListNode* res = new ListNode(-1);
        ListNode* p = res;
        while (!pq.empty()) {
            p->next = pq.top();
            pq.pop();
            p = p->next;
            if (p->next) pq.push(p->next);
        }
        return res->next;
    }
};

int main() {}