#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    unordered_map<int, int> m;

    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return dfs(nums, target);
    }

    int dfs(vector<int> nums, int target) {
        if (target == 0) return 1;

        int res = 0;
        for (auto p : nums) {
            if (p <= target) {
                int left = target - p;
                if (m.find(left) == m.end()) {
                    int cur = dfs(nums, left);
                    m[left] = cur;
                    res += cur;
                } else {
                    res += m[left];
                }
            } else {
                break;
            }
        }
        return res;
    }
};

int main() {}