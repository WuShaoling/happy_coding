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
    vector<vector<int> > groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int> > mm;

        for (int i = 0; i < groupSizes.size(); i++)
            mm[groupSizes[i]].push_back(i);

        vector<vector<int> > res;
        for (map<int, vector<int> >::iterator it = mm.begin(); it != mm.end(); it++) {
            for (int i = 0; i < it->second.size();) {
                vector<int> t;
                int j = 0;
                for (; j < it->first; j++) 
                    t.push_back(it->second[i + j]);
                i += j;
                res.push_back(t);
            }
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<int> groupSizes = {3, 3, 3, 3, 3, 1, 3};
    vector<vector<int> > res = solution.groupThePeople(groupSizes);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}