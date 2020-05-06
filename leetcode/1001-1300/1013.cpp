#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size();

        int sum = 0;
        for (int i = 0; i < n; i++) sum += A[i];
        if (sum % 3 != 0) return false;
        sum /= 3;

        int leftSum = A[0];
        int rightSum = A[n - 1];
        for (int i = 0, j = n - 1; i + 1 < j;) {
            if (leftSum == sum && leftSum == rightSum) return true;
            if (leftSum != sum) leftSum += A[++i];
            if (rightSum != sum) rightSum += A[--j];
        }
        return false;
    }
};

// i        j
// 1 2 3 4  5  6
// 1 3 6 10 15 21

int main() {
    Solution s;
    vector<int> v = {3, 3, 6, 5, -2, 2, 5, 1, -9, 4};
    cout << s.canThreePartsEqualSum(v);
}