#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        vector<int> res;

        long sum1 = 0;
        for (int i : array1) sum1 += i;

        map<long, bool> mm2;
        long sum2 = 0;
        for (int i : array2) {
            sum2 += i;
            mm2[i] = true;
        }

        long diff = sum1 - sum2;
        if ((diff & 1) == 1) return res;
        diff /= 2;

        for (int i : array1) {
            if (mm2[i - diff]) {
                res.push_back(i);
                res.push_back(i - diff);
                return res;
            }
        }
        return res;
    }
};

int main() {}