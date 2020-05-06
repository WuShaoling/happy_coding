#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct term {
    int value;
    int label;
    term(int v, int l) {
        value = v;
        label = l;
    }
};

bool cmp(term a, term b) { return a.value > b.value; }

class Solution {
   public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels,
                              int num_wanted, int use_limit) {
        vector<term> elem;
        for (int i = 0; i < values.size(); i++)
            elem.push_back(term(values[i], labels[i]));
        sort(elem.begin(), elem.end(), cmp);

        int res = 0;
        map<int, int> mm;
        map<int, int>::iterator it;
        for (term t : elem) {
            if (num_wanted == 0) return res;

            it = mm.find(t.label);
            if (it != mm.end() && it->second >= use_limit) continue;

            res += t.value;
            mm[t.label]++;
            num_wanted--;
        }

        return res;
    }
};

int main() {
    vector<int> values = {9,8,8,7,6};
    vector<int> labels = {0,0,0,1,1};
    Solution s;
    cout << s.largestValsFromLabels(values, labels, 3, 1);
}