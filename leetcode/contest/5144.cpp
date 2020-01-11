#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int calSum(vector<vector<int>>& mat, int rL, int rR, int cU, int cD) {
        int sum = 0;
        for (int i = rL; i <= rR; i++)
            for (int j = cU; j <= cD; j++) sum += mat[i][j];
        return sum;
    }

    // vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
    //     vector<vector<int>> res;
    //     int Row = mat.size();
    //     int Col = mat[0].size();
    //     for (int i = 0; i < Row; i++) {
    //         vector<int> t;
    //         for (int j = 0; j < Col; j++) {
    //             int rL = i - K;
    //             int rR = i + K;
    //             if (rL >= Row || rR < 0) {
    //                 t.push_back(0);
    //                 continue;
    //             }

    //             int cU = j - K;
    //             int cD = j + K;
    //             if (cU >= Col || cD < 0) {
    //                 t.push_back(0);
    //                 continue;
    //             }
    //             t.push_back(calSum(mat, max(0, rL), min(Row - 1, rR),
    //                                     max(cU, 0), min(cD, Col - 1)));
    //         }
    //         res.push_back(t);
    //     }
    //     return res;
    // }

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        vector<vector<int>> res;
        int Row = mat.size();
        int Col = mat[0].size();
        for (int i = 0; i < Row; i++) {
            vector<int> line;
            for (int j = 0; j < Col; j++) {
                int rL = max(0, i - K);
                int rR = min(Row - 1, i + K);
                int cU = max(j - K, 0);
                int cD = min(j + K, Col - 1);
                line.push_back(calSum(mat, rL, rR, cU, cD));
            }
            res.push_back(line);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> res = s.matrixBlockSum(mat, 2);
    for (vector<int> v : res) {
        for (int t : v) cout << t << " ";
        cout << endl;
    }
}