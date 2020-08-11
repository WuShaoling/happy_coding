#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// vector<vector<int>> res;
int res = 0;
void search(vector<int>& v, int start, int n, int cur) {
    if (cur > n || start >= v.size()) return;
    res++;
    for (int i = start; i < v.size() && v[i] + cur <= n; i++) {
        if (i > start && v[i] == v[i - 1]) continue;
        search(v, i + 1, n, cur + v[i]);
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> v(m);
    for (int i = 0; i < m; i++) cin >> v[i];
    sort(v.begin(), v.end());

    vector<int> path;
    search(v, 0, n, 0);
    cout << res << endl;
}

// 0
// 1 2 4
