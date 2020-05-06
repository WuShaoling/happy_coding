#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* leftNodes = head->next->next;

        ListNode* temp = head->next;
        temp->next = head;
        head->next = swapPairs(leftNodes);
        return temp;
    }
};

int main() {}