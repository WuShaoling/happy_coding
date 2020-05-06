#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cmp {
    bool operator()(int a, int b) { return a > b; }
};

class Solution {
   public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int cur = 0;
        if (n <= 0) return -1;
        priority_queue<long, vector<long>, greater<long>> q;
        q.push(1);
        while (!q.empty()) {
            long top = q.top();
            q.pop();
            cur++;

            if (cur == n) return top;

            // 去重
            while (!q.empty() && q.top() == top) q.pop();

            for (int i : primes) {
                q.push(top * i);
            }
        }
        return -1;
    }
};

void test() {
    priority_queue<long, vector<long>, cmp> q;
    vector<int> nums = {3, 2, 4, 5, 53, 1, 1};
    for (int i : nums) {
        q.push(i);
    }
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
}

int main() { test(); }