#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int> &A, int K) {
        int maxx = A[0];
        int minn = A[0];
        for (int i = 1; i < A.size(); i++) {
            if (maxx < A[i]) maxx = A[i];
            if (minn > A[i]) minn = A[i];
        }
        return max(maxx - minn - 2 * K, 0);
    }
};


int main() {
    Solution solution;

    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);

    cout << solution.smallestRangeI(A, 3);
}
