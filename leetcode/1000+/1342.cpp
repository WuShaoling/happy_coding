#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
   public:
    int minSetSize(vector<int>& arr) {
        map<int, int> mm;
        for (int i : arr) {
            if (mm.find(i) != mm.end()) {
                mm[i]++;
            } else {
                mm[i] = 1;
            }
        }

        vector<int> t;
        for (map<int, int>::iterator it = mm.begin(); it != mm.end(); it++) {
            t.push_back(it->second);
        }
        sort(t.begin(), t.end());

        int count = 0;
        int n = arr.size() / 2;
        for (int i = t.size() - 1; i >= 0; i--) {
            n -= t[i];
            count++;
            if (n <= 0) {
                return count;
            }
        }
        return count;
    }
};

int main() {}