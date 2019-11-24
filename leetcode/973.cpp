#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cmp{
    bool operator()(const vector<int> &a, const vector<int> &b){
        if(a[0]*a[0]+a[1]*a[1] > b[0]*b[0]+b[1]*b[1]){
            return 1;
        } else {
            return 0;
        }
    }
};

class Solution {
public:
    vector<vector<int> > kClosest(vector<vector<int> >& points, int K) {
        priority_queue< vector<int>, vector<vector<int> >, struct cmp> pq;
        for(int i=0; i<points.size(); i++){
            pq.push(points[i]);
        }
        vector<vector<int> > result;
        for(int i=0; i<K; i++){
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};

int main(){
    Solution solution;
    
    vector<vector<int> > points;
    
    vector<int> v1;
    v1.push_back(3);
    v1.push_back(3);
    points.push_back(v1);
    
    vector<int> v2;
    v2.push_back(5);
    v2.push_back(-1);
    points.push_back(v2);
    
    vector<int> v3;
    v3.push_back(-2);
    v3.push_back(4);
    points.push_back(v3);
    
    vector<vector<int> > result = solution.kClosest(points, 2);
    
    for (int i=0; i<result.size(); i++){
        cout << result[i][0] << " " << result[i][1] << endl;
    }
    return 0;
}
