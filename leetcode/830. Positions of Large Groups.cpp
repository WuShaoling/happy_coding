#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        if (S.size() < 3) {
            return res;
        }
        int begin = 0;
        for (int i = 1; i < S.size(); i++) {
            if (S[i] != S[i - 1]) {
                if (i - begin >= 3) {
                    res.push_back({begin, i - 1});
                }
                begin = i;
            }
        }
        if (S.size() - begin >= 3) {
            res.push_back({begin, (int) (S.size() - 1)});
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> res = solution.largeGroupPositions("abcdddeeeeaabbbcd");
    for (int i = 0; i < res.size(); i++) {
        cout << res[i][0] << " " << res[i][1] << endl;
    }
}
