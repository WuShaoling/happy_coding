#include <iostream>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> ps;
        for (ListNode* list : lists) {
            ps.push_back(list);
        }
        ListNode* head = new ListNode(0);
        ListNode* mergeCur = head;
        while (true) {
            ListNode* minNode = NULL;
            int index = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (ps[i]) {
                    if (minNode == NULL) {
                        minNode = ps[i];
                        index = i;
                    } else if (minNode->val < ps[i]->val) {
                        minNode = ps[i];
                        index = i;
                    }
                }
            }
            mergeCur->next = minNode;
            mergeCur = mergeCur->next;
            if (minNode == NULL) break;
            ps[index] = ps[index]->next;
        }
        return head->next;
    }
};

int main() {}