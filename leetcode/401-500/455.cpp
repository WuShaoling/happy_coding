#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int ret = 0;
        int gp = 0;
        for (int i = 0; i < s.size() && gp < g.size(); i++) {
            if (s[i] >= g[gp]) {
                gp++;
                ret++;
            }
        }

        return ret;
    }
};

int main() {
    Solution solution;

    vector<int> g = {1, 2};
    vector<int> s = {1, 2, 3};

    cout << solution.findContentChildren(g, s);
}