#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> permutation(string S) {
        vector<bool> visited(S.size(), false);
        char path[S.size() + 1];
        helper(S, path, 0, visited);
        return res;
    }

    void helper(string& S, char cur[], int index, vector<bool>& visited) {
        if (index == S.size()) {
            res.push_back(string(cur, 0, index));
            return;
        }

        for (int i = 0; i < S.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                cur[index] = S[i];
                helper(S, cur, index + 1, visited);
                visited[i] = false;
            }
        }
    }

    vector<string> res;
};

// class Solution {
//    public:
//     vector<string> permutation(string S) {
//         vector<bool> visited(S.size(), false);
//         helper(S, "", 0, visited);
//         return res;
//     }

//     void helper(string& S, string cur, int index, vector<bool>& visited) {
//         if (index == S.size()) {
//             res.push_back(cur);
//             return;
//         }

//         for (int i = 0; i < S.size(); i++) {
//             if (!visited[i]) {
//                 visited[i] = true;
//                 helper(S, cur + S[i], index + 1, visited);
//                 visited[i] = false;
//             }
//         }
//     }

//     vector<string> res;
// };

int main() {
    Solution s;
    vector<string> res = s.permutation("abc");
    for (string str : res) cout << str << endl;
}