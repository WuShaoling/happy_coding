#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) {
            vector<vector<int>> t;
            return t;
        }

        vector<vector<int>> matrix(n);
        for (int i = 0; i < n; i++) matrix[i].resize(n);

        int L = 0, R = n - 1;
        int U = 0, D = n - 1;
        int total = n * n;
        int begin = 1;
        while (true) {
            for (int i = L; i <= R; i++) matrix[U][i] = begin++;
            if (begin > total) return matrix;

            for (int i = U + 1; i <= D; i++) matrix[i][R] = begin++;
            if (begin > total) return matrix;

            for (int i = R - 1; i >= L; i--) matrix[D][i] = begin++;
            if (begin > total) return matrix;

            for (int i = D - 1; i > U; i--) matrix[i][L] = begin++;
            if (begin > total) return matrix;

            L++, R--;
            U++, D--;
        }
        return matrix;
    }
};

int main() {
    Solution s;
    vector<vector<int>> res = s.generateMatrix(5);
    for (vector<int> line : res) {
        for (int i : line) cout << i << " ";
        cout << endl;
    }
}