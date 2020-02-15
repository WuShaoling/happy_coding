#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int> > removeInterval(vector<vector<int> >& intervals,
                                        vector<int>& toBeRemoved) {
        vector<vector<int> > res;

        for (vector<int> v : intervals) {
            if (toBeRemoved[0] <= v[0] && toBeRemoved[1] >= v[1]) {
                continue;
            }
            if (toBeRemoved[0] > v[0] && toBeRemoved[0] < v[1] &&
                toBeRemoved[1] >= v[1]) {
                vector<int> t1 = {v[0], toBeRemoved[0]};
                res.push_back(t1);
            } else if (toBeRemoved[0] <= v[0] && toBeRemoved[1] > v[0] &&
                       toBeRemoved[1] < v[1]) {
                vector<int> t1 = {toBeRemoved[1], v[1]};
                res.push_back(t1);
            } else if (toBeRemoved[0] > v[0] && toBeRemoved[1] < v[1]) {
                vector<int> t1 = {v[0], toBeRemoved[0]};
                vector<int> t2 = {toBeRemoved[1], v[1]};
                res.push_back(t1);
                res.push_back(t2);
            } else {
                res.push_back(v);
            }
        }

        return res;
    }
};

int main() {
    Solution s;

    vector<vector<int> > res = {{0, 100}};
    vector<vector<int> > res2 = {{0, 50}};
    s.removeInterval(res, res2);
}