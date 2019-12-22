#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;

        sort(nums.begin(), nums.end());

        int res = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] > nums[k])
                        res++;
                    else
                        break;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> t = {2, 2, 3, 4};
    cout << s.triangleNumber(t);
}