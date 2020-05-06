#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
   public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency,
                       int k) {
        vector<vector<int>> es;
        for (int i = 0; i < speed.size(); i++) {
            es.push_back({efficiency[i], speed[i]});
        }
        sort(es.rbegin(), es.rend());

        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        long long res = 0;
        for (int i = 0; i < es.size(); i++) {
            sum += es[i][1];
            pq.push(es[i][1]);
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            res = max(res, sum * es[i][0]);
        }

        return res % 1000000007;
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 2, 3, 4, 5};
    sort(a.rbegin(), a.rend());
    for (int i : a) cout << i << " ";
}