#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    unordered_map<int, int> F;

    int father(int x) {
        if (F.count(x) == 0) return x;
        if (F[x] != x) F[x] = father(F[x]);
        return F[x];
    }

    int longestConsecutive(vector<int>& nums) {
        F.clear();
        for (auto x : nums) {
            F[x] = father(x);
            if (F.count(x - 1) > 0) F[father(x - 1)] = father(x);
            if (F.count(x + 1) > 0) F[father(x)] = father(x + 1);
        }

        // for(unordered_map<int, int>::iterator it = F.begin(); it!=F.end();
        // it++){
        //     cout << it->first << " " << it->second << endl;
        // }

        int res = 0;
        for (auto x : nums)
            if (father(x) - x + 1 > res) res = father(x) - x + 1;
        return res;
    }
};

int main() {
    Solution s;
    vector<int> v = {100, 4, 200, 1, 3, 2};
    cout << s.longestConsecutive(v) << endl;
}