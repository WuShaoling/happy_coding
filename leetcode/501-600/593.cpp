#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3,
                     vector<int>& p4) {
        vector<vector<int>> p = {p1, p2, p3, p4};
        sort(p.begin(), p.end(), [](vector<int>& p1, vector<int>& p2) {
            if (p1[0] == p2[0]) return p1[1] < p2[1];
            return p1[0] < p2[0];
        });

        return dist(p[0], p[1]) != 0 && dist(p[0], p[1]) == dist(p[1], p[3]) &&
               dist(p[1], p[3]) == dist(p[3], p[2]) &&
               dist(p[3], p[2]) == dist(p[2], p[0]) &&
               dist(p[0], p[3]) == dist(p[1], p[2]);
    }

    int dist(vector<int>& p1, vector<int>& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) +
               (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
};

int main() {
    Solution s;
    vector<int> p1 = {1, 0};
    vector<int> p2 = {-1, 0};
    vector<int> p3 = {0, 1};
    vector<int> p4 = {0, -1};
    cout << s.validSquare(p1, p2, p3, p4);
}
