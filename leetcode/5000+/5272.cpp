#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int countServers(vector<vector<int> >& grid) {
        int total = 0;
        vector<int> column;
        for (int i = 0; i < grid.size(); i++) {
            int count = 0;
            int index = 0;
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    total++;
                    count++;
                    index = j;
                }
            }
            if (count == 1) {
                column.push_back(index);
            }
        }
        for (int i = 0; i < column.size(); i++) {
            int count = 0;
            for (int j = 0; j < grid.size(); j++) {
                if (grid[j][column[i]] == 1) {
                    count++;
                }
            }
            if (count == 1) {
                total--;
            }
        }
        return total;
    }
};

int main() {
    Solution s;
    // vector<vector<int> > grid = {
    //     {1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    vector<vector<int> > grid = {{1, 0}, {1, 1}};

    cout << s.countServers(grid);
}