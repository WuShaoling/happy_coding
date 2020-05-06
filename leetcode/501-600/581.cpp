#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() <= 1) return 0;

        int left = 20000;
        stack<int> s;
        for (int i = 0; i < nums.size(); i++) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                left = min(left, s.top());
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) s.pop();

        int right = -1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                right = max(right, s.top());
                s.pop();
            }
            s.push(i);
        }

        return right - left > 0 ? right - left + 1 : 0;
    }
};

int main() {}