#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        unordered_map<int, int> hash_table;
        priority_queue<int> lo;                              // max heap
        priority_queue<int, vector<int>, greater<int> > hi;  // min heap

        int i = 0;  // index of current incoming element being processed

        // initialize the heaps
        while (i < k) lo.push(nums[i++]);
        for (int j = 0; j < k / 2; j++) {
            hi.push(lo.top());
            lo.pop();
        }

        while (true) {
            // get median of current window
            medians.push_back(
                k & 1 ? lo.top() : ((double)lo.top() + (double)hi.top()) * 0.5);

            if (i >= nums.size()) break;  // break if all elements processed

            int out_num = nums[i - k],  // outgoing element
                in_num = nums[i++];     // incoming element

            int left = 0, right = 0;

            // number `out_num` exits window
            if (!lo.empty() && out_num <= lo.top()) {
                left--;
            } else {
                right--;
            }
            hash_table[out_num]++;

            // number `in_num` enters window
            if (!lo.empty() && in_num <= lo.top()) {
                left++;
                lo.push(in_num);
            } else {
                right++;
                hi.push(in_num);
            }

            // 左边需要更多的元素
            if (left < right) {
                lo.push(hi.top());
                hi.pop();
            } else if (left > right) {
                hi.push(lo.top());
                lo.pop();
            }

            // 保证堆顶的元素是窗口内的
            while (!lo.empty() && hash_table[lo.top()] > 0) {
                hash_table[lo.top()]--;
                lo.pop();
            }
            while (!hi.empty() && hash_table[hi.top()]) {
                hash_table[hi.top()]--;
                hi.pop();
            }
        }

        return medians;
    }
};

int main() {}