#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
   public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (!pHead) return NULL;

        vector<RandomListNode*> v1;
        vector<RandomListNode*> v2;
        map<RandomListNode*, int> pos;
        RandomListNode* newHead = new RandomListNode(0);
        RandomListNode* p1 = pHead;
        RandomListNode* p2 = newHead;

        int index = 0;
        while (p1) {
            p2->next = new RandomListNode(p1->label);
            v1.push_back(p1);
            v2.push_back(p2->next);
            pos[p1] = index;
            p1 = p1->next;
            p2 = p2->next;
            index++;
        }

        p1 = pHead;
        p2 = newHead->next;
        while (p1) {
            if (p1->random != NULL) {
                int p = pos[p1->random];
                p2->random = v2[p];
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        return newHead->next;
    }
};

int main() {}