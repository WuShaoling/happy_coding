#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Less{
    bool operator()(const vector<int>& v1, const vector<int>& v2){
        return v1[0] < v2[0]; 
    }
};

class Solution {
public:

    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        vector<vector<int> > res;
        if(intervals.size() == 0){
            return res;
        }

        sort(intervals.begin(), intervals.end(), Less());
        res.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= res.back()[1]){
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int> > intervals = {
        {1,4},
        {4,10},
    };
    vector<vector<int> > res = s.merge(intervals);
    for(int i=0; i<res.size(); i++){
        cout << res[i][0] << " " << res[i][1] << endl;
    }
}