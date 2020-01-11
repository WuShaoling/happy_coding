#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    Solution() {
        vector<int> first = {1};
        triangle.push_back(first);
        for (int i = 2; i <= 34; i++) {
            vector<int> line = {1};
            for (int j = 1; j < i - 1; j++) {
                line.push_back(triangle[i - 2][j - 1] + triangle[i - 2][j]);
            }
            line.push_back(1);
            triangle.push_back(line);
        }
    }

    vector<int> getRow(int rowIndex) { return triangle[rowIndex]; }

    vector<vector<int>> triangle;
};

int main() {
    Solution s;
    vector<int> res = s.getRow(3);

    for (int i : res) cout << i << " ";
    cout << endl;
}