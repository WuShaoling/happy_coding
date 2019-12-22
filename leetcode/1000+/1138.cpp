#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string alphabetBoardPath(string target) {
        vector<string> board = {"abcde", "fghij", "klmno",
                                "pqrst", "uvwxy", "z"};

        vector<int> mm[26];
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                mm[board[i][j] - 'a'] = {i, j};

        string res = "";
        int x = 0, y = 0;
        for (int i = 0; i < target.size(); i++) {
            vector<int> p = mm[target[i] - 'a'];

            // 上下移动
            if (x < p[0]) {  //下移
                for (; x < p[0]; x++) {
                    if (x == 4 && p[1] == 0) break;
                    res.append("D");
                }
            } else
                for (; x > p[0]; x--) res.append("U");

            // 左右移动
            if (y < p[1])
                for (; y < p[1]; y++) res.append("R");
            else
                for (; y > p[1]; y--) res.append("L");

            // 再次向下移动
            if (x < p[0])
                for (; x < p[0]; x++) res.append("D");

            res.append("!");
        }
        return res;
    }
};
/*
"abcde"
"fghij"
"klmno"
"pqrst"
"uvwxy"
"z"
*/

int main() {
    Solution s;
    cout << s.alphabetBoardPath("code");
}