#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;
        map<int, int> mm;
        for (int i : nums) mm[i]++;

        while (!mm.empty()) {
            int count = 0;
            int pre = 0;
            for (map<int, int>::iterator it = mm.begin(); it != mm.end();) {
                if (count == k) break;
                if (count == 0 || it->first - pre == 1) {
                    pre = it->first;
                    count++;
                    it->second--;
                    if (it->second == 0)
                        mm.erase(it++);
                    else
                        it++;
                } else {
                    return false;
                }
            }
            if (count != k) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    cout << s.isPossibleDivide(nums, 4);
}