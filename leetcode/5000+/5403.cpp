#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
   public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> ans(mat[0]);
        for (int i = 1; i < mat.size(); i++) {
            multiset<int> st;
            for (int x : ans) {
                for (int y : mat[i]) {
                    st.insert(x + y);
                }
            }
            ans.assign(st.begin(), st.end());
            ans.resize(min(k, (int)ans.size()));
        }
        return ans.back();
    }
};

/*

[1,3,11]
[2,4,6]

[1, 10, 10]
[1, 4,  5]
[2, 3,  6]
*/

int main() {}