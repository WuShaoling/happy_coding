#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;

        if (sum <= 2) return res;

        for (int i = 1; i < sum; i++) {  // 1 2
            int v = i;
            for (int j = i + 1; j < sum; j++) {  // 3
                v += j;
                if (v > sum) {
                    break;
                } else if (v == sum) {
                    vector<int> line;
                    for (int k = i; k <= j; k++) line.push_back(k);
                    res.push_back(line);
                }
            }
        }
        return res;
    }

    vector<vector<int> > FindContinuousSequence2(int sum) {
        vector<vector<int> > res;

        if (sum <= 2) return res;

        int left = 1;
        int right = 2;
        int mid = (sum + 1) / 2;
        int v = left + right;
        while (right <= mid) {  // 100  - 50 51   101 50 51
            if (v < sum) {
                right++;
                v += right;
            } else if (v > sum) {
                v -= left;
                left++;
            } else {
                vector<int> line;
                for (int i = left; i <= right; i++) line.push_back(i);
                res.push_back(line);
                right++;
                v += right;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int> > res = s.FindContinuousSequence2(100);
    for (vector<int> line : res) {
        for (int i : line) cout << i << " ";
        cout << endl;
    }
}