#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k <= 0) {
            vector<int> t;
            return t;
        }
        if (k > input.size()) k = input.size();

        priority_queue<int> q;
        for (int v : input) {
            if (q.size() < k) {
                q.push(v);
            } else if (v < q.top()) {
                q.pop();
                q.push(v);
            }
        }

        vector<int> res(k);
        while (!q.empty()) {
            res[k - 1] = q.top();
            q.pop();
            k--;
        }
        return res;
    }
};

int main() {
    vector<int> v = {4, 5, 1, 6, 2, 7, 3, 8};
    Solution s;
    vector<int> res = s.GetLeastNumbers_Solution(v, 4);
    for (int i : res) {
        cout << i << " ";
    }
}
