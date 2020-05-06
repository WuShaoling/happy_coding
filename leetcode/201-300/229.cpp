#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() < 1) return nums;
        // 投票阶段
        int cand1 = 0, count1 = 0;
        int cand2 = 0, count2 = 0;
        for (int num : nums) {
            if (cand1 == num) {
                count1++;
                continue;
            }
            if (cand2 == num) {
                count2++;
                continue;
            }
            if (count1 == 0) {
                cand1 = num;
                count1++;
                continue;
            }
            if (count2 == 0) {
                cand2 = num;
                count2++;
                continue;
            }
            count1--;
            count2--;
        }
        // 计数阶段
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == cand1)
                count1++;
            else if (num == cand2)
                count2++;
        }
        vector<int> ans;
        if (count1 > nums.size() / 3) ans.push_back(cand1);
        if (count2 > nums.size() / 3) ans.push_back(cand2);
        return ans;
    }
};

int main() {}