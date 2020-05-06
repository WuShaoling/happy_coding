#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long res = INT_MAX, diff;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) return 0;
            long diff = a[i] - b[j];
            long abs_diff = diff > 0 ? diff : -diff;
            res = res > abs_diff ? abs_diff : res;

            if (a[i] > b[j])
                j++;
            else if (a[i] < b[j])
                i++;
            else
                return 0;
        }
        return res;
    }
};

// 1 2 3 4  5
// 5 6 7 40 50

int main() {
    Solution s;
    vector<int> a = {1, 3, 15, 11, 2};
    vector<int> b = {23, 127, 235, 19, 8};
    cout << s.smallestDifference(a, b);
}