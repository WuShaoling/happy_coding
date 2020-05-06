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
    bool operator()(ListNode* a, ListNode* b) { return b->val < a->val; }
};

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;  // less, 大根堆
        for (ListNode* list : lists) {
            if (!list) continue;
            pq.push(list);
        }

        ListNode* ans = new ListNode(-1);
        ListNode* p = ans;
        while (!pq.empty()) {
            ListNode* temp = pq.top();
            p->next = temp;
            p = p->next;

            temp = temp->next;
            if (temp) pq.push(temp);
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<ListNode*> lists;
    s.mergeKLists(lists);
}