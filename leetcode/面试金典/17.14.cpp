#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (k == 0 || arr.size() == 0) {
            vector<int> res;
            return res;
        }

        priority_queue<int> pq;
        for (int i : arr) {
            if (pq.size() < k) {
                pq.push(i);
            } else if (i < pq.top()) {
                pq.pop();
                pq.push(i);
            }
        }

        vector<int> res(pq.size());
        for (int i = pq.size() - 1; i >= 0; i--) {
            res[i] = pq.top();
            pq.pop();
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> arr = {5, 4, 3, 2, 1};
    vector<int> res = s.smallestK(arr, 3);
    for (int i : res) cout << i << " ";
}