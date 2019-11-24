#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int> &A) {
        if (A.size() < 3 || A[1] <= A[0]) {
            return false;
        }
        bool up = true;
        for (int i = 2; i < A.size(); i++) {
            if (A[i] == A[i - 1]) {
                return false;
            }
            if (up) {
                if (A[i] < A[i - 1]) {
                    up = false;
                }
            } else {
                if (A[i] > A[i - 1]) {
                    return false;
                }
            }
        }
        return up ? false : true;
    }
};


int main() {
    Solution solution;

    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(2);
    A.push_back(1);

    cout << solution.validMountainArray(A);
}
