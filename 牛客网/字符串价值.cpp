#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    string s = "";
    int n;
    int count[26] = {0};
    priority_queue<int, vector<int> > q;

    cin >> s;
    cin >> n;
    if (s.length() == 0) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < s.length(); i++) {
        count[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            q.push(count[i]);
        }
    }

    while (n && !q.empty()) {
        int t = q.top();
        q.pop();
        if (--t > 0) {
            q.push(t);
        }
        n--;
    }

    int res = 0;
    while (!q.empty()) {
        int t = q.top();
        res += t * t;
        q.pop();
    }
    cout << res << endl;
};