#include <cmath>
#include <iostream>

using namespace std;

class Solution {
   public:
    int mySqrt(int x) {
        int left = 1, right = x;
        while (left < right) {
            int mid = left + (right - left) / 2;
            long mid2 = (long)(mid)*mid;
            cout << left << " " << right << " " << mid << " " << mid2 << " "
                 << INT_MAX << endl;
            if (mid2 == x) {
                return mid;
            } else if (mid2 > x) {
                if ((long)(mid - 1) * (mid - 1) <= (long)x) return mid - 1;
                right = mid - 1;
            } else {
                if ((long)(mid + 1) * (mid + 1) > (long)x) return mid;
                left = mid + 1;
            }
        }
        return left;
    }
};
// 1 2
int main() {
    Solution s;
    cout << s.mySqrt(INT_MAX) << endl;
}