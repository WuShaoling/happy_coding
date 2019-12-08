#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int minDeletionSize(vector<string>& A) {
        if (A.size() == 0) return 0;

        int res = 0;
        for (int col = 0; col < A[0].size(); col++) {
            for (int row = 0; row < A.size(); row++) {
                if (row == 0) continue;
                if (A[row][col] >= A[row - 1][col]) continue;
                res++;
                break;
            }
        }

        return res;
    }
};

int main() {}