#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        // 右边拿K张
        int rightSum = 0;
        for (int i = n - k; i < n; i++) {
            rightSum += cardPoints[i];
        }

        if (k == n) return rightSum;

        int ans = 0;
        int leftSum = 0;
        for (int i = 0, j = n - k; j < n; i++, j++) {
            ans = max(ans, leftSum + rightSum);
            leftSum += cardPoints[i];
            rightSum -= cardPoints[j];
        }
        ans = max(ans, leftSum + rightSum);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << s.maxScore(nums, 5);
}