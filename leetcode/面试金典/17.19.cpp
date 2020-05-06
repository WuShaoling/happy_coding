#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> missingTwo(vector<int>& nums) {
        int myxor = 0;
        int i = 1;
        for (; i <= nums.size(); i++) {
            myxor ^= nums[i - 1];
            myxor ^= i;
        }
        myxor ^= i;
        i++;
        myxor ^= i;

        int firstOne = 1;
        while ((myxor & firstOne) == 0) firstOne <<= 1;

        int a = 0;
        i = 1;
        for (; i <= nums.size(); i++) {
            if ((i & firstOne) == 0) a ^= i;
            if ((nums[i - 1] & firstOne) == 0) a ^= nums[i - 1];
        }
        if ((i & firstOne) == 0) a ^= i;
        i++;
        if ((i & firstOne) == 0) a ^= i;

        vector<int> res = {a, myxor ^ a};
        return res;
    }
};

// 1 2 5
// 1 2 3 4 5

int main() {}