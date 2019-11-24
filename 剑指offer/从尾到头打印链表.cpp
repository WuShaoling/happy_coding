#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode *head) {
        vector<int> array;

        while (head != NULL) {
            array.push_back(head->val);
            head = head->next;
        }

        for (int i = 0, j = array.size() - 1; i < j; i++, j--) {
            array[i] ^= array[j];
            array[j] ^= array[i];
            array[i] ^= array[j];

        }

        return array;
    }


//    vector<int> printListFromTailToHead(ListNode *head) {
//        vector<int> res;
//        recurrent(head, res);
//        return res;
//    }
//
//    void recurrent(ListNode *p, vector<int> &res) {
//        if (p != NULL) {
//            recurrent(p->next, res);
//            res.push_back(p->val);
//        }
//    }
};

int main() {
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    for (int i = 1; i <= 10; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    p = head;

    Solution solution;
    vector<int> res = solution.printListFromTailToHead(p);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}
