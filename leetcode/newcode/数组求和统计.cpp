#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int countLR(vector<int>& a, vector<int>& b) {
        int res = 0;
        for (int l = 0; l < a.size(); l++) {
            int sum = 0;
            for (int r = l; r < a.size(); r++) {
                sum += a[r];
                if (sum == b[l] + b[r]) {
                    res++;
                }
            }
        }
        return res;
    }
};

int main() {}