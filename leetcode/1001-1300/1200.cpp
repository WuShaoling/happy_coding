#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int> > minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        vector<vector<int> > res;
        int _min = INT_MAX;

        for (int i = 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];
            if (diff < _min) {
                _min = diff;
                res.clear();
                res.push_back({arr[i - 1], arr[i]});
            } else if (diff == _min) {
                res.push_back({arr[i - 1], arr[i]});
            }
        }
        return res;
    }
};

int main() {}