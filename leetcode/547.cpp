#include <iostream>
#include <vector>

using namespace std;

class UnionFind{
public:
    UnionFind(int n){
        for(int i=0; i<n; i++){
            f.push_back(i);
        }
    }

    void merge(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px != py){
            f[py] = px;
        }
    }

    int find(int x){
        if(f[x] == x){
            return x;
        }else{
            f[x] = find(f[x]);
            return f[x];
        }
    }

    int getGroup(){
        int res = 0;
        for(int i=0; i<f.size(); i++){
            if(f[i] == i){
                res++;
            }
        }
        return res;
    }

private:
    vector<int> f;
};

class Solution {
public:
    int findCircleNum(vector<vector<int> >& M) {

        UnionFind uf(M.size());

        for(int i=0; i<M.size(); i++){
            for(int j=0; j<i; j++){
                if(M[i][j])
                    uf.merge(i, j); 
            }
        }
        return uf.getGroup();
    }
};

int main(){
    Solution s;
    // vector<vector<int> > v = {{1,1,0}, {1,1,0}, {0,1,1}};
    vector<vector<int> > v = {{1,1,0}, {1,1,1}, {0,1,1}};
    cout << s.findCircleNum(v) << endl;
}