#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    int nthUglyNumber(int n) {
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

            q.push(top * 2);
            q.push(top * 3);
            q.push(top * 5);
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.nthUglyNumber(10) << endl;
}