#include <cmath>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0) {
            return false;
        }
        unordered_map<long, long> mm;
        int n = nums.size();
        long w = (long)t + 1;
        for (int i = 0; i < n; i++) {
            if (i > k) mm.erase(getId(nums[i - k - 1], w));
            long id = getId(nums[i], w);
            if (mm.find(id) != mm.end()) return true;
            if (mm.find(id + 1) != mm.end() && mm[id + 1] - nums[i] < w)
                return true;
            if (mm.find(id - 1) != mm.end() && nums[i] - mm[id - 1] < w)
                return true;
            mm[id] = (long)nums[i];
        }
        return false;
    }

    long getId(long num, long w) {
        if (num >= 0) return num / w;
        return (num + 1) / w - 1;
    }

    // bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    //     multiset<long> s;
    //     //   j     i
    //     // 0 1 2 3 4
    //     // 1 2 3 4 5
    //     // 1 2 3
    //     // k = 3
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (s.size() == k + 1) {
    //             s.erase(nums[i - k - 1]);
    //         }
    //         long left = nums[i] - t;
    //         long right = nums[i] + t;
    //         auto it = s.lower_bound(left);  //找第一个>= left的数
    //         if (it != s.end() && *it >= left && *it <= right) {
    //             return true;
    //         }
    //         s.insert(nums[i]);
    //     }
    //     return false;
    // }
};

int main() {}
