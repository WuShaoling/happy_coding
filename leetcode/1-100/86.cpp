#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* partition(ListNode* head, int x) {
        // if (!head || !head->next) return head;

        ListNode* newHead = new ListNode(-1);
        newHead->next = head;

        ListNode* greater = newHead;
        while (true) {
            // 找到第一个大于等于x的节点
            while (greater->next && greater->next->val < x) {
                greater = greater->next;
            }
            if (!greater->next) return newHead->next;

            // 从 greater 开始找第一个小于 x 的节点
            ListNode* less = greater;
            while (less->next && less->next->val >= x) {
                less = less->next;
            }
            if (!less->next) return newHead->next;

            ListNode* temp = less->next;
            less->next = temp->next;

            temp->next = greater->next;
            greater->next = temp;
            // 把 less 插入到 greater 之前
        }

        return newHead->next;
    }
};

int main() {}