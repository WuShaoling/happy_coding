#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums) {
        map<int, map<pair<int, int>, int>> mm;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                mm[i + j][{i, j}] = nums[i][j];
            }
        }

        vector<int> ans;
        for (auto &it : mm) {
            for (auto it2 = it.second.rbegin(); it2 != it.second.rend();
                 it2++) {
                ans.push_back((*it2).second);
            }
        }

        return ans;
    }
};

/*

[1,2,3,4,5],
[6,7],
[8],
[9,10,11],
[12,13,14,15,16]

00 01 02
10 11 12
20 21 22

1 3 6
2 5 8
4 7 9

1  3 6  10
2  5 9  13
4  8 12 15
7 11 14 16
*/
int main() {
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    vector<int> ans = s.findDiagonalOrder(matrix);
    for (int i : ans) cout << i << " ";
}