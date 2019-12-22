#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class UnionFind {
   public:
    void merge(string x, string y, double value) {
        if (f.count(x) == 0) {
            f[x] = x;
            v[x] = 1.0;
        }
        if (f.count(y) == 0) {
            f[y] = y;
            v[y] = 1.0;
        }

        string px = find(x);
        string py = find(y);
        f[py] = px;
        v[py] = v[x] / v[y] * value;
    }

    string find(string x) {
        if (f[x] == x) {
            return x;
        } else {
            // string tx = x;
            // while(f[tx] != tx){
            //     v[tx] *= v[f[tx]];
            //     tx = f[tx];
            // }
            // f[x] = find(f[x]);
            // return f[x];
            string fa = find(f[x]);
            v[x] *= v[f[x]];
            return f[x] = fa;
        }
    }

    void show() {
        for (map<string, string>::iterator it = f.begin(); it != f.end();
             it++) {
            cout << it->first << " " << it->second << endl;
        }
        cout << endl;

        for (map<string, double>::iterator it = v.begin(); it != v.end();
             it++) {
            cout << it->first << " " << it->second << endl;
        }
        cout << endl;
    }

    double find2(string x, string y) {
        if (f.count(x) == 0 || f.count(y) == 0) {
            return -1.0;
        }

        string px = find(x);
        string py = find(y);
        if (px != py) {
            return -1;
        }

        return v[y] * 1.0 / v[x];
    }

   private:
    map<string, string> f;
    map<string, double> v;
};

class Solution {
   public:
    vector<double> calcEquation(vector<vector<string> >& equations,
                                vector<double>& values,
                                vector<vector<string> >& queries) {
        UnionFind uf;

        for (int i = 0; i < equations.size(); i++) {
            uf.merge(equations[i][0], equations[i][1], values[i]);
        }

        vector<double> res;
        for (int i = 0; i < queries.size(); i++) {
            double ans = uf.find2(queries[i][0], queries[i][1]);
            res.push_back(ans);
        }

        return res;
    }
};

int main() {
    Solution s;

    vector<vector<string> > equations = {
        {"e", "d"}, {"d", "c"}, {"b", "a"}, {"c", "b"}};
    vector<double> values = {2.0, 2.0, 2.0, 2.0};
    vector<vector<string> > queries = {{"e", "a"}};

    vector<double> res = s.calcEquation(equations, values, queries);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}