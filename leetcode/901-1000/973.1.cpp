#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int getDistance(const vector<int>& p) { return p[0] * p[0] + p[1] * p[1]; }

struct point_cmp {
    bool operator()(const vector<int>& p1, const vector<int>& p2) {
        return getDistance(p1) < getDistance(p2);
    }
};

class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, point_cmp> q;
        for (int i = 0; i < points.size(); i++) {
            q.push(points[i]);
            if (q.size() > K) {
                q.pop();
            }
        }
        int n = q.size();
        vector<vector<int>> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = q.top();
            q.pop();
        }
        return res;
    }
};

int main() {}