#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        int before = -1;
        int after = -1;

        int i = 0;
        while (nums[i] <= 0) i++;

        for (int i : nums) {
        }
    }
};

int main() {}