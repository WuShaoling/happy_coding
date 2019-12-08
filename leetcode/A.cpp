#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string tictactoe(vector<vector<int> >& moves) {
        int flag[3][3] = {0};

        for (int i = 0; i < moves.size(); i++) {
            vector<int> v = moves[i];

            if (i % 2 == 0)  // X
                flag[v[0]][v[1]] = 1;
            else  // O
                flag[v[0]][v[1]] = 2;

            // 先按行找
            for (int row = 0; row < 3; row++) {
                int X = 0, O = 0;
                for (int col = 0; col < 3; col++) {
                    if (flag[row][col] == 1)
                        X++;
                    else if (flag[row][col] == 2)
                        O++;
                }
                if (X == 3)
                    return "A";
                else if (O == 3)
                    return "B";
            }

            // 再按列找
            for (int col = 0; col < 3; col++) {
                int X = 0, O = 0;
                for (int row = 0; row < 3; row++) {
                    if (flag[row][col] == 1)
                        X++;
                    else if (flag[row][col] == 2)
                        O++;
                }
                if (X == 3)
                    return "A";
                else if (O == 3)
                    return "B";
            }

            // 对角线找
            int X = 0, O = 0;
            for (int t = 0; t < 3; t++) {
                if (flag[t][t] == 1)
                    X++;
                else if (flag[t][t] == 2)
                    O++;
            }
            if (X == 3)
                return "A";
            else if (O == 3)
                return "B";

            X = 0, O = 0;
            for (int a = 0, b = 2; a < 3, b >= 0; a++, b--) {
                if (flag[a][b] == 1)
                    X++;
                else if (flag[a][b] == 2)
                    O++;
            }
            if (X == 3)
                return "A";
            else if (O == 3)
                return "B";
        }

        if (moves.size() == 9) return "Draw";
        return "Pending";
    }
};
int main() { Solution solution; }