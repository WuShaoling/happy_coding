#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> mm;
        for (int i = 0; i < nums.size(); i++) {
            int d = target - nums[i];
            map<int, int>::iterator it = mm.find(d);
            if (it == mm.end()) {
                mm[nums[i]] = i;
            } else {
                res.push_back(it->second);
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};

int main() {}