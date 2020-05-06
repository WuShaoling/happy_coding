#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
   public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if (k == 0 || arr.size() == 0) return res;

        priority_queue<int, vector<int>> q;
        for (int i : arr) {
            if (q.size() < k) {
                q.push(i);
                continue;
            }

            if (i < q.top()) {
                q.pop();
                q.push(i);
            }
        }

        while (!q.empty()) {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> v = {0, 1, 2, 1};
    vector<int> res = s.getLeastNumbers(v, 1);
    for (int i : res) cout << i << " ";
}

// 4 3 2 1