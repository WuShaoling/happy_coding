#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> computeSimilarities(vector<vector<int>>& docs) {
        map<int, vector<int>> doc_to_index;
        for (int i = 0; i < docs.size(); i++) {
            for (int doc : docs[i]) {
                doc_to_index[doc].push_back(i);
            }
        }

        map<pair<int, int>, int> inters;
        for (auto& it : doc_to_index) {
            for (int i = 0; i < it.second.size(); i++) {
                for (int j = i + 1; j < it.second.size(); j++) {
                    inters[{it.second[i], it.second[j]}]++;
                }
            }
        }

        vector<string> ans;
        int i, j;
        for (auto& it : inters) {
            i = it.first.first;
            j = it.first.second;
            int n = docs[i].size() + docs[j].size() - it.second;
            char dest[20];
            sprintf(dest, "%d,%d: %.4lf", i, j, it.second * 1.0 / n + 1e-9);
            ans.push_back(string(dest));
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> docs = {};
    Solution s;
    vector<string> ans = s.computeSimilarities(docs);
    for (string str : ans) cout << str << endl;
}