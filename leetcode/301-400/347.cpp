#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct cmp {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }
};

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mm;
        for (int i : nums) mm[i]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for (auto it : mm) {
            if (q.size() < k) {
                q.push(it);
            } else if (q.top().second < it.second) {
                q.pop();
                q.push(it);
            }
        }
        int n = q.size();
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            res[i] = q.top().first;
            q.pop();
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> v = {1, 1, 1, 2, 2, 3};
    vector<int> res = s.topKFrequent(v, 2);
    for (int i : res) cout << i << " ";
}

// 5 4 3 2 1