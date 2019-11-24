#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <queue>

using namespace std;

class Solution {
public:
    string largestTimeFromDigits(vector<int> &A) {
        sort(A.begin(), A.end(), greater<>());
        do {
            int a = A[0] * 10 + A[1];
            int b = A[2] * 10 + A[3];
            if (a >= 0 && a <= 23 && b >= 0 && b <= 59) {
                return to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
            }
        } while (prev_permutation(A.begin(), A.end()));
        return "";
    }
};

//int main() {
//    Solution solution;
//    vector<int> a;
//    a.push_back(5);
//    a.push_back(5);
//    a.push_back(5);
//    a.push_back(5);
//
//    cout << solution.largestTimeFromDigits(a);
//
//    return 0;
//}
