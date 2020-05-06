#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Solution {
   public:
    string reorganizeString(string S) {
        int arr[26] = {0};
        for (char c : S) {
            arr[c - 'a']++;
            if (arr[c - 'a'] > (S.size() + 1) / 2) return "";
        }

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) pq.push({arr[i], i});
        }

        int i = 0;
        string ans = S;
        while (!pq.empty()) {
            int count = pq.top().first;
            char c = pq.top().second + 'a';
            pq.pop();
            while (count--) {
                if (i >= ans.size()) i = 1;
                ans[i] = c;
                i += 2;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    cout << s.reorganizeString("aab");
}