#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int judge(int i, int Ai) {
        if ((i % 2 == 0 && Ai % 2 == 0) || (i % 2 != 0 && Ai % 2 != 0)) {
            return 0;
        } else if (i % 2 != 0 && Ai % 2 == 0) {
            return -1;
        } else {
            return 1;
        }
    }

    vector<int> sortArrayByParityII(vector<int> &A) {
        int si = 0, sj = A.size() - 1;
        while (si < sj) {
            while (si < sj && judge(si, A[si]) == 0) {
                si++;
            }
            while (si < sj && judge(sj, A[sj]) == 0) {
                sj--;
            }
            int t = judge(si, A[si]);
            for (int j = sj; si < j; j--) {
                if (t + judge(j, A[j]) == 0) {
                    swap(A[si], A[j]);
                    break;
                }
            }
            si++;
        }
        return A;
    }
};

int main() {

    Solution solution;

    vector<int> param;
    param.push_back(2);
    param.push_back(3);
    param.push_back(1);
    param.push_back(1);
    param.push_back(4);
    param.push_back(0);
    param.push_back(0);
    param.push_back(4);
    param.push_back(3);
    param.push_back(3);

    vector<int> res = solution.sortArrayByParityII(param);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}
