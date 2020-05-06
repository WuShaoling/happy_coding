#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Node {
   public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class NewNode {
    Node* oldNode;
    Node* newNode;

    NewNode(int _val) { newNode->val = _val; }
};

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> mm;

        queue<Node*> q;
        q.push(node);
        mm[node] = new Node(node->val);

        while (!q.empty()) {
            Node* t = q.front();
            q.pop();

            for (Node* n : t->neighbors) {
                if (mm.find(n) == mm.end()) {  // 节点不存在
                    q.push(n);
                    mm[n] = new Node(n->val);
                }
                mm[t]->neighbors.push_back(mm[n]);
            }
        }

        return mm[node];
    }
};

int main() {}