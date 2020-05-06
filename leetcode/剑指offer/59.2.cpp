#include <iostream>
#include <deque>
#include <queue>

using namespace std;

class MaxQueue {
   public:
    MaxQueue() {}

    int max_value() {
        if (q_max.empty()) return -1;
        return q_max.front();
    }

    void push_back(int value) {
        while (!q_max.empty() && q_max.back() < value) q_max.pop_back();
        q_max.push_back(value);
        q.push(value);
    }

    int pop_front() {
        if (q.empty()) return -1;
        int n = q.front();
        q.pop();

        if (!q_max.empty() && n == q_max.front()) q_max.pop_front();
        return n;
    }

   private:
    queue<int> q;
    deque<int> q_max;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

int main() {}