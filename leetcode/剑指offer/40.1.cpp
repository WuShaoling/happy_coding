#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        // 大根堆
        if (arr.empty() || k == 0) return {};

        priority_queue<int, vector<int>, std::less<int>> q;

        for (int i : arr) {
            if (q.size() < k) {
                q.push(i);
            } else {
                if (i < q.top()) {
                    q.push(i);
                    q.pop();
                }
            }
        }

        vector<int> res(q.size());
        int i = 0;
        while (!q.empty()) {
            res[i++] = q.top();
            q.pop();
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> arr = {3, 2, 1, 4, 5, 6};
    vector<int> res = s.getLeastNumbers(arr, 3);
    for (int i : res) cout << i << " ";
}